package scala.tests

import com.google.caliper.BeforeExperiment
import com.google.caliper.Benchmark
import com.google.caliper.api.VmOptions

import scala.implementation.{MicroSet, Use}
import java.util.HashSet
import java.util.Random
import java.util.TreeSet

import com.google.caliper.runner.CaliperMain

/**
  * Created by pxl on 03/04/17.
  */

@VmOptions (Array ("-XX:-TieredCompilation") )
class MicroSet_Benchmark_Add {

  val NUMBER_OF_TEST_OBJECT: Int = 30
  val microInnerSet = new MicroSet[TestObject](Use.INNER_SET,NUMBER_OF_TEST_OBJECT)
  val microArraySet = new MicroSet[TestObject](Use.ARRAY_SET,NUMBER_OF_TEST_OBJECT)
  val microHAshSet = new MicroSet[TestObject](Use.HASH_SET,NUMBER_OF_TEST_OBJECT)

  val hashSet = new HashSet[TestObject]
  val treeSet = new TreeSet[TestObject]

  var tabTestObject: Array[TestObject] = Array.ofDim(NUMBER_OF_TEST_OBJECT)
  var tabRandomInt: Array[Int] = Array.ofDim(NUMBER_OF_TEST_OBJECT)

  @BeforeExperiment()
  def setUp() =
  {
    val rand: Random = new Random
    for(i <- 0 to NUMBER_OF_TEST_OBJECT) tabTestObject(i) = TestObject(rand.nextInt())
    for(i <- 0 to NUMBER_OF_TEST_OBJECT) tabRandomInt(i) = rand.nextInt(NUMBER_OF_TEST_OBJECT)
  }

  @Benchmark
  def testAdd_TreeSet(reps: Int) =
  {
     for(i <- 0 to reps)
     {
       for(j <- 0 to NUMBER_OF_TEST_OBJECT) treeSet.add(tabTestObject(tabRandomInt(j)))
     }
  }

  @Benchmark
  def testAdd_HashSet(reps: Int) =
  {
    for(i <- 0 to reps)
    {
      for(j <- 0 to NUMBER_OF_TEST_OBJECT) hashSet.add(tabTestObject(tabRandomInt(j)))
    }
  }

  @Benchmark
  def testAdd_InnerSet(reps: Int) =
  {
    for(i <- 0 to reps)
    {
      for(j <- 0 to NUMBER_OF_TEST_OBJECT) microInnerSet.add(tabTestObject(tabRandomInt(j)))
    }
  }

  @Benchmark
  def testAdd_InnerArraySet(reps: Int) =
  {
    for(i <- 0 to reps)
    {
      for(j <- 0 to NUMBER_OF_TEST_OBJECT) microArraySet.add(tabTestObject(tabRandomInt(j)))
    }
  }

  @Benchmark
  def testAdd_InnerHashSet(reps: Int) =
  {
    for(i <- 0 to reps)
    {
      for(j <- 0 to NUMBER_OF_TEST_OBJECT) microHAshSet.add(tabTestObject(tabRandomInt(j)))
    }
  }

  def main(args: Array[String]): Unit = {
    val args = Array[String]("-i", "runtime", "-r", "ADD scale=" + NUMBER_OF_TEST_OBJECT + ", object_number=" + NUMBER_OF_TEST_OBJECT)
    CaliperMain.main(classOf[MicroSet_Benchmark_Add], args)
  }
}
