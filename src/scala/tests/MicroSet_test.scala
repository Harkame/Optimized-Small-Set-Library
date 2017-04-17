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
  }

  @Test
  def test_addElement_Already_in()
  {
    val res = microSet.add(testObject)
    print(res)
    print(microSet.toString)
    assertFalse(res)
  }

  @Test
  def test_addElement()
  {
    val res2 = microSet.add(new TestObject(2))
    print(microSet.toString)
    assertTrue(res2)
  }

  @Test
  def test_removeElement_Not_in_Microset()
  {
    val res = microSet.remove(new TestObject(1))
    print(microSet.toString)
    assertFalse(res)
  }

  @Test
  def test_removeElement()
  {
    val res2 = microSet.remove(testObject)
    print(microSet.toString)
    assertTrue(res2)
  }

  @Test
  def test_contains_wrongElem()
  {
    val res = microSet.contains(new TestObject(1))
    assertFalse(res)
  }

  @Test
  def test_contains_goodElem()
  {
    val res2 = microSet.contains(testObject)
    assertTrue(res2)
  }

  @Test
  def clear()
  {
    microSet.clear()
    assertTrue(microSet.isEmpty())
  }

  @Test
  def isEmpty()
  {
    assertFalse(microSet.isEmpty)
  }

  @Test
  def size()
  {
    assertEquals(microSet.size, 1)
  }

  @Test
  def addAllElements()
  {
    val microSetAdd = new MicroSet[TestObject]
    val testObject2 = new TestObject(2)
    val testObject3 = new TestObject(3)

    microSetAdd.add(testObject2)
    microSetAdd.add(testObject3)

    assertEquals(microSet.size, 1)
    microSet.addAll(microSetAdd)
    print(microSet.toString)
    assertEquals(microSet.size, 3)
  }

  @Test
  def removeAllElements()
  {
    val testObject2 = new TestObject(2)
    val testObject3 = new TestObject(3)

    //MicroSetRemove contains [testObject2 , testObject]
    val microSetRemove = new MicroSet[TestObject]
    microSetRemove.add(testObject2)
    microSetRemove.add(testObject)

    //MicroSet contains [testObject, testObject2, testObject3]
    microSet.add(testObject2)
    microSet.add(testObject3)

    assertEquals(microSet.size, 3)
    microSet.removeAll(microSetRemove)
    assertEquals(microSet.size, 1)

    //MicroSet contains [testObject3]
  }

  @Test
  def retainAllElements()
  {
    val testObject2 = new TestObject(2)
    val testObject3 = new TestObject(3)

    //MicroSetRetain contains [testObject2 , testObject]
    val microSetRetain = new MicroSet[TestObject]
    microSetRetain.add(testObject2)
    microSetRetain.add(testObject)

    //MicroSet contains [testObject, testObject3]
    microSet.add(testObject3)

    assertEquals(microSet.size, 2)
    microSet.retainAll(microSetRetain)
    assertEquals(microSet.size, 1)

    //MicroSet contains [testObject]
  }

  @Test
  def containsAllElements()
  {
    val testObject2 = new TestObject(2)
    val testObject3 = new TestObject(3)

    //MicroSetRetain contains [testObject2 , testObject]
    val microSetContains = new MicroSet[TestObject]
    microSetContains.add(testObject2)
    microSetContains.add(testObject)

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
