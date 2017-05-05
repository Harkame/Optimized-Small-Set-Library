package scala.tests

import java.util.{HashSet, Random, TreeSet}

import com.google.caliper.{BeforeExperiment, Benchmark}
import com.google.caliper.api.VmOptions
import com.google.caliper.runner.CaliperMain

import scala.implementation.{MicroSet, Use}

/**
  * Created by pxl on 03/04/17.
  */

@VmOptions (Array ("-XX:-TieredCompilation") )
class MicroSet_Benchmark_Add {

  val microInnerSet = new MicroSet[TestObject]()
  MicroSet.use = Use.ARRAY_SET
  val microArraySet = new MicroSet[TestObject]()
  MicroSet.use = Use.HASH_SET
  val microHAshSet = new MicroSet[TestObject]()

  val hashSet = new HashSet[TestObject]
  val treeSet = new TreeSet[TestObject]

  var tabTestObject: Array[TestObject] = Array.ofDim(runner.NUMBER_OF_TEST_OBJECT)
  var tabRandomInt: Array[Int] = Array.ofDim(runner.NUMBER_OF_TEST_OBJECT)

  @BeforeExperiment()
  def setUp() =
  {
    val rand: Random = new Random
    for(i <- 0 until runner.NUMBER_OF_TEST_OBJECT) tabTestObject(i) = new TestObject(rand.nextInt(13))
    for(i <- 0 until runner.NUMBER_OF_TEST_OBJECT) tabRandomInt(i) = rand.nextInt(runner.NUMBER_OF_TEST_OBJECT)
  }

  @Benchmark
  def testAdd_TreeSet(reps: Int) =
  {
     for(i <- 0 to reps)
     {
       for(j <- 0 until runner.NUMBER_OF_TEST_OBJECT) treeSet.add(tabTestObject(tabRandomInt(j)))
     }
  }

  @Benchmark
  def testAdd_HashSet(reps: Int) =
  {
    for(i <- 0 to reps)
    {
      for(j <- 0 until runner.NUMBER_OF_TEST_OBJECT) hashSet.add(tabTestObject(tabRandomInt(j)))
    }
  }

  @Benchmark
  def testAdd_InnerSet(reps: Int) =
  {
    for(i <- 0 to reps)
    {
      for(j <- 0 until runner.NUMBER_OF_TEST_OBJECT) microInnerSet.add(tabTestObject(tabRandomInt(j)))
    }
  }

  @Benchmark
  def testAdd_InnerArraySet(reps: Int) =
  {
    for(i <- 0 to reps)
    {
      for(j <- 0 until runner.NUMBER_OF_TEST_OBJECT) microArraySet.add(tabTestObject(tabRandomInt(j)))
    }
  }

  @Benchmark
  def testAdd_InnerHashSet(reps: Int) =
  {
    for(i <- 0 to reps)
    {
      for(j <- 0 until runner.NUMBER_OF_TEST_OBJECT) microHAshSet.add(tabTestObject(tabRandomInt(j)))
    }
  }
}

object runner {
  val NUMBER_OF_TEST_OBJECT: Int = 30
  def main(args: Array[String]): Unit = {
    val args = Array[String]("-i", "runtime", "-r", "ADD scale=" + NUMBER_OF_TEST_OBJECT + ", object_number=" + NUMBER_OF_TEST_OBJECT)
    CaliperMain.main(classOf[MicroSet_Benchmark_Add], args)
  }
}
