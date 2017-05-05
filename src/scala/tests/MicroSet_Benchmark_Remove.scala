package scala.tests

import java.util.{HashSet, Random, TreeSet}

import com.google.caliper.api.VmOptions
import com.google.caliper.runner.CaliperMain
import com.google.caliper.{BeforeExperiment, Benchmark}

import scala.implementation.MicroSet


/**
  * Created by pxl on 03/04/17.
  */

@VmOptions (Array ("-XX:-TieredCompilation") )
class MicroSet_Benchmark_Remove{

  val NUMBER_OF_TEST_OBJECT: Int = 30
  val microInnerSet = new MicroSet[TestObject]()
  val microArraySet = new MicroSet[TestObject]()
  val microHAshSet = new MicroSet[TestObject]()

  val hashSet = new HashSet[TestObject]
  val treeSet = new TreeSet[TestObject]

  var tabTestObject: Array[TestObject] = Array.ofDim(NUMBER_OF_TEST_OBJECT)
  var tabRandomInt: Array[Int] = Array.ofDim(NUMBER_OF_TEST_OBJECT)

  @BeforeExperiment()
  def setUp() =
  {
    val rand: Random = new Random
    for(i <- 0 to NUMBER_OF_TEST_OBJECT) tabTestObject(i) = TestObject(rand.nextInt())
    for(i <- 0 to NUMBER_OF_TEST_OBJECT/2)
    {
      microArraySet.add(tabTestObject(i))
      microHAshSet.add(tabTestObject(i))
      microInnerSet.add(tabTestObject(i))

      hashSet.add(tabTestObject(i))
      treeSet.add(tabTestObject(i))
    }
    for(i <- 0 to NUMBER_OF_TEST_OBJECT) tabRandomInt(i) = rand.nextInt(NUMBER_OF_TEST_OBJECT)
  }

  @Benchmark
  def testRemove_TreeSet(reps: Int) =
  {
    for(i <- 0 to reps)
    {
      for(j <- 0 to NUMBER_OF_TEST_OBJECT/4) treeSet.remove(tabTestObject(tabRandomInt(j)))
    }
  }

  @Benchmark
  def testRemove_HashSet(reps: Int) =
  {
    for(i <- 0 to reps)
    {
      for(j <- 0 to NUMBER_OF_TEST_OBJECT/4) hashSet.remove(tabTestObject(tabRandomInt(j)))
    }
  }

  @Benchmark
  def testRemove_InnerSet(reps: Int) =
  {
    for(i <- 0 to reps)
    {
      for(j <- 0 to NUMBER_OF_TEST_OBJECT) microInnerSet.remove(tabTestObject(tabRandomInt(j)))
    }
  }

  @Benchmark
  def testRemove_InnerArraySet(reps: Int) =
  {
    for(i <- 0 to reps)
    {
      for(j <- 0 to NUMBER_OF_TEST_OBJECT) microArraySet.remove(tabTestObject(tabRandomInt(j)))
    }
  }

  @Benchmark
  def testRemove_InnerHashSet(reps: Int) =
  {
    for(i <- 0 to reps)
    {
      for(j <- 0 to NUMBER_OF_TEST_OBJECT) microHAshSet.remove(tabTestObject(tabRandomInt(j)))
    }
  }

  def main(args: Array[String]): Unit = {
    val args = Array[String]("-i", "runtime", "-r", "ADD scale=" + NUMBER_OF_TEST_OBJECT + ", object_number=" + NUMBER_OF_TEST_OBJECT)
    CaliperMain.main(classOf[MicroSet_Benchmark_Remove], args)
  }

}
