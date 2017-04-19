package scala.tests

import org.junit.jupiter.api.Assertions._
import org.junit.jupiter.api.{BeforeEach, Test}

import scala.implementation.MicroSet

object MicroSet_test {

  private[tests] var microSet: MicroSet[TestObject] = _
  private[tests] val testObject = TestObject(1)

  @BeforeEach
  def setUp()
  {
    microSet = MicroSet[TestObject]
    microSet.add(testObject)
    println("====================")
    println("Début : " + microSet.toString)
  }

  @Test
  def test_addElement_Already_in()
  {
    println("Test : addElement_Already_in")
    val res = microSet.add(testObject)
    println("Résultat : " + microSet.toString)
    assertFalse(res)
  }

  @Test
  def test_addElement()
  {
    println("Test : addElement")
    val res2 = microSet.add(new TestObject(2))
    println("Résultat : " + microSet.toString)
    assertTrue(res2)
  }

  @Test
  def test_removeElement_Not_in_Microset()
  {
    println("Test : removeElement_Not_in_Microset")
    val res = microSet.remove(new TestObject(1))
    println("Résultat : " + microSet.toString)
    assertFalse(res)
  }

  @Test
  def test_removeElement()
  {
    println("Test : removeElement")
    val res2 = microSet.remove(testObject)
    println("Résultat : " + microSet.toString)
    assertTrue(res2)
  }

  @Test
  def test_contains_wrongElem()
  {
    println("Test : contains_wrongElem")
    val res = microSet.contains(new TestObject(1))
    println("Résultat : " + res)
    assertFalse(res)
  }

  @Test
  def test_contains_goodElem()
  {
    println("Test : contains_goodElem")
    val res = microSet.contains(testObject)
    println("Résultat : " + res)
    assertTrue(res)
  }

  @Test
  def clear()
  {
    println("Test : clear")
    microSet.clear()
    println("Résultat : " + microSet.toString)
    assertTrue(microSet.isEmpty())
  }

  @Test
  def isEmpty()
  {
    println("Test : isEmpty")
    assertFalse(microSet.isEmpty)
  }

  @Test
  def size()
  {
    println("Test : size")
    assertEquals(microSet.size, 1)
  }

  @Test
  def addAllElements()
  {
    println("Test : addAllElements")
    val microSetAdd = new MicroSet[TestObject]
    val testObject2 = new TestObject(2)
    val testObject3 = new TestObject(3)

    microSetAdd.add(testObject2)
    microSetAdd.add(testObject3)
    println("MicroSet à Add : " + microSetAdd.toString)

    assertEquals(microSet.size, 1)
    microSet.addAll(microSetAdd)
    println("Résultat : " + microSet.toString)
    assertEquals(microSet.size, 3)
  }

  @Test
  def removeAllElements()
  {
    println("Test : removeAllElements")
    val testObject2 = new TestObject(2)
    val testObject3 = new TestObject(3)

    //MicroSetRemove contains [testObject2 , testObject]
    val microSetRemove = new MicroSet[TestObject]
    microSetRemove.add(testObject2)
    microSetRemove.add(testObject)
    println("MicroSet à Remove : " + microSetRemove.toString)

    //MicroSet contains [testObject, testObject2, testObject3]
    microSet.add(testObject2)
    microSet.add(testObject3)

    assertEquals(microSet.size, 3)
    microSet.removeAll(microSetRemove)
    println("Résultat : " + microSet.toString)
    assertEquals(microSet.size, 1)

    //MicroSet contains [testObject3]
  }

  @Test
  def retainAllElements()
  {
    println("Test : retainAllElements")
    val testObject2 = new TestObject(2)
    val testObject3 = new TestObject(3)

    //MicroSetRetain contains [testObject2 , testObject]
    val microSetRetain = new MicroSet[TestObject]
    microSetRetain.add(testObject2)
    microSetRetain.add(testObject)
    println("MicroSet à Retain : " + microSetRetain.toString)

    //MicroSet contains [testObject, testObject3]
    microSet.add(testObject3)

    assertEquals(microSet.size, 2)
    microSet.retainAll(microSetRetain)
    println("Résultat : " + microSet.toString)
    assertEquals(microSet.size, 1)

    //MicroSet contains [testObject]
  }

  @Test
  def containsAllElements()
  {
    println("Test : containsAllElements")
    val testObject2 = new TestObject(2)
    val testObject3 = new TestObject(3)

    //MicroSetRetain contains [testObject2 , testObject]
    val microSetContains = new MicroSet[TestObject]
    microSetContains.add(testObject2)
    microSetContains.add(testObject)
    println("MicroSet à Contains : " + microSetContains.toString)

    //MicroSet contains [testObject, testObject2, testObject3]
    microSet.add(testObject2)
    microSet.add(testObject3)

    assertTrue(microSet.containsAll(microSetContains))
  }

  def toArray()
  {
    //Todo
  }
}
