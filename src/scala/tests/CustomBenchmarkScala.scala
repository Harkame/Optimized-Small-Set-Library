package scala.tests

import java.io.{File, FileWriter, IOException}

import scala.Array._
import scala.implementation.{MicroSet, Use}
import scala.implementation.Use.Use
import scala.util.Random

/**
  * Created by pxl on 05/05/17.
  */
object CustomBenchmarkScala
{

  private val MEGABYTE = 1024L * 1024L
  private var RANDOM_SEED = 1
  private var POOL_SIZE = 15
  private var STOCK_SIZE = 10
  private var LISTE_CROISSANTE_SIZE = 50
  private var NOMBRE_TIRAGE = 10
  private var ITERATION = 1000
  private var random = new Random(RANDOM_SEED)

  def bytesToMegaBytes(bytes: Long): Long = bytes / MEGABYTE

  def randomBetwen(low: Int, max: Int): Int = random.nextInt(max - low) + low

  def oneRun(use: Use): Unit = {
    MicroSet.use = use
    random = new Random(RANDOM_SEED)
    var testObjects: Array[TestObject] = new Array[TestObject](POOL_SIZE)
    for (i <- 0 until POOL_SIZE) {
      testObjects :+ new TestObject(random.nextInt())
    }

    var randomIndiceListeCroissante = ofDim[Int](ITERATION, NOMBRE_TIRAGE)
    var randomIndiceStock = ofDim[Int](ITERATION, NOMBRE_TIRAGE)

    for (z <- 0 until ITERATION) {
      for (i <- 0 until NOMBRE_TIRAGE) {
        randomIndiceListeCroissante(z)(i) = randomBetwen(0, LISTE_CROISSANTE_SIZE)
      }
      for (i <- 0 until NOMBRE_TIRAGE) {
        randomIndiceStock(z)(i) = randomBetwen(0, STOCK_SIZE)
      }
    }

    var numberOfObject = new Array[Int](STOCK_SIZE)
    for (i <- 0 until STOCK_SIZE) {
      numberOfObject(i) = randomBetwen(1, 4)
    }

    var stock: Array[MicroSet[TestObject]] = new Array[MicroSet[TestObject]](STOCK_SIZE)
    for (i <- 0 until STOCK_SIZE) {
      var microSet: MicroSet[TestObject] = new MicroSet[TestObject]
      for (j <- 0 until LISTE_CROISSANTE_SIZE) {
        microSet.add(testObjects(randomBetwen(0, POOL_SIZE)))
      }
      stock :+ microSet
    }

    var listeCroissante: Array[MicroSet[TestObject]] = new Array[MicroSet[TestObject]](LISTE_CROISSANTE_SIZE)
    val runtime = Runtime.getRuntime
    runtime.gc()
    
    val startTime = System.nanoTime

    for (z <- 0 until ITERATION) {
      listeCroissante = new Array[MicroSet[TestObject]](LISTE_CROISSANTE_SIZE)
      for (i <- 0 until LISTE_CROISSANTE_SIZE) {
        listeCroissante :+ new MicroSet
      }
      for (i <- 0 until NOMBRE_TIRAGE) {
        var indice = randomIndiceListeCroissante(z)(i)
        var increment: MicroSet[TestObject] = stock(randomIndiceStock(z)(i))
        var j = 0;
        while (j < LISTE_CROISSANTE_SIZE && !increment.isEmpty()) {
          increment = listeCroissante(j).addAllAndPropagate(increment)
          j += j
        }
      }
    }

    val stopTime = System.nanoTime
    val elapsedTime = stopTime - startTime
    // Calculate the used memory
    val memory = runtime.totalMemory - runtime.freeMemory
    println("Elapsed time is : " + elapsedTime + " nanos (" + elapsedTime / 1000L + " micros)")
    println("Used memory is: " + memory + "bytes (" + bytesToMegaBytes(memory) + " Mbytes)")

    val file = new File(use.toString + "test.txt")
    try
    {
      val writer = new FileWriter(file)
      val s = new StringBuilder
      for (i <- 0 until LISTE_CROISSANTE_SIZE) {
        s.append(listeCroissante(i).size() + "\n")
      }
      writer.write(s.toString)
      writer.close
    }
    catch
    {
      case ioe: IOException => ioe.printStackTrace()
    }
  }

  def main(args: Array[String]): Unit = {
    if(args.length > 0)
    {
      RANDOM_SEED = args(1).toInt
      POOL_SIZE = args(2).toInt
      STOCK_SIZE = args(3).toInt
      LISTE_CROISSANTE_SIZE = args(4).toInt
      NOMBRE_TIRAGE = args(5).toInt
      ITERATION = args(6).toInt
    }

    args(0) match{
      case "ARRAY" =>
      {
        println("~~~~~~~~ ARRAY_SET ~~~~~~~~")
        oneRun(Use.ARRAY_SET)
      }
      case "HASH" =>
      {
        println("~~~~~~~~ HASH_SET ~~~~~~~~")
        oneRun(Use.HASH_SET)
      }
      case "INNER" =>
      {
        println("~~~~~~~~ INNER_SET ~~~~~~~~")
        oneRun(Use.INNER_SET)
      }
    }

    println("~~~~~~~~ Fin des tests ~~~~~~~~")
  }
}

