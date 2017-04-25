package scala.implementation

import java.util.Iterator

/**
  * Created by pxl on 29/03/17.
  */

object InnerSetIterator
{
  def apply[T](p_innerSet: InnerSet[T]): InnerSetIterator[T] = new InnerSetIterator(p_innerSet)
}

class InnerSetIterator[T](innerSet: InnerSet[T]) extends Iterator[T] {

  var index: Int = 0

  override def next(): T =
  {
    index += 1
    val t = innerSet.getElement(index)
    t.get
  }

  override def hasNext: Boolean = index != innerSet.getSize
}
