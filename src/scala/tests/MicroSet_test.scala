package scala.tests

import org.junit.jupiter.api.{BeforeEach, Test}
import scala.implementation.MicroSet
import org.junit.jupiter.api.Assertions._

object MicroSet_test {

  private[tests] var microSet: MicroSet[TestObject] = _
  private[tests] val testObject = TestObject(1)

  @BeforeEach
  private[tests] def setUp()
  {
    microSet = MicroSet[TestObject]
    microSet.add(testObject)
  }

  @Test
  private[tests] def test_addElement_Already_in()
  {
    val res = microSet.add(testObject)
    assertFalse(res)
  }

  @Test
  private[tests] def test_addElement()
  {
    val res2 = microSet.add(new TestObject(2))
    assertTrue(res2)
  }

  @Test
  private[tests] def test_removeElement_Not_in_Microset()
  {
    val res = microSet.remove(new TestObject(1))
    assertFalse(res)
  }

  @Test
  private[tests] def test_removeElement()
  {
    val res2 = microSet.remove(testObject)
    assertTrue(res2)
  }

  @Test
  private[tests] def test_contains_wrongElem()
  {
    val res = microSet.contains(new TestObject(1))
    assertFalse(res)
  }

  @Test private[tests] def test_contains_goodElem()
  {
    val res2 = microSet.contains(testObject)
    assertTrue(res2)
  }

  @Test
  private[tests] def clear()
  {
    microSet.clear()
    assertFalse(microSet.contains(testObject))
  }

  @Test private[tests] def isEmpty()
  {
    assertFalse(microSet.isEmpty)
  }

  @Test
  private[tests] def size()
  {
    assertEquals(microSet.size, 1)
  }

  @Test
  private[tests] def addAllElements()
  {
    val microSetAdd = new MicroSet[TestObject]
    val testObject2 = new TestObject(2)
    val testObject3 = new TestObject(3)

    microSetAdd.add(testObject2)
    microSetAdd.add(testObject3)

    assertEquals(microSet.size, 1)
    microSet.addAll(microSetAdd)
    assertEquals(microSet.size, 3)
  }

  @Test
  private[tests] def removeAllElements()
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
  private[tests] def retainAllElements()
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
  private[tests] def containsAllElements()
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

  private[tests] def toArray()
  {
    //Todo
  }
}
