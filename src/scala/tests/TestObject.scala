package scala.tests

/**
  * Created by pxl on 03/04/17.
  */

object TestObject
{
  def apply(p_id: Int): TestObject = new TestObject(p_id)
}

class TestObject(p_id: Int) extends Comparable[TestObject]
{
  val id: Int = p_id

  override def compareTo(p_testObject: TestObject): Int =
  {
    var res: Int = 0
    if (id < p_testObject.id) res = -1
    if (id > p_testObject.id) res = 1
    res
  }
}
