package scala.tests

/**
  * Created by pxl on 03/04/17.
  */

object TestObject
{
  def apply(id: Int): TestObject = new TestObject(id)
}

class TestObject(id: Int) extends Comparable[TestObject]
{
  override def compareTo(p_testObject: TestObject): Int =
  {
    var res: Int = 0
    if (id < p_testObject.id) res = -1
    if (id > p_testObject.id) res = 1
    res
  }
}
