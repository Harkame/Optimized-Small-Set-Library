package scala.implementation

object InnerSet_0{
  def apply[T]: InnerSet_0[T] = new InnerSet_0[T]
}

class InnerSet_0[T] extends AbstractInnerSet[T]{

  override def addElement(p_element: T): InnerSet[T] = InnerSet_1(p_element)

  override def addUnchecked(p_element: T): InnerSet[T] = addElement(p_element)

  override def addAllElements(p_innerSet: InnerSet[T]): InnerSet[T] = p_innerSet

  override def containsElement(p_element: Object): Boolean = false

  override def containsAllElements(p_innerSet: InnerSet[T]): Boolean = false

  override def getElement(p_index: Int): Option[T] = null

  override def removeElement(p_element: Object): InnerSet[T] = this

  override def removeAllElements(p_innerSet: InnerSet[T]): InnerSet[T] = this

  override def retainAllElements(p_innerSet: InnerSet[T]): InnerSet[T] = this

  override def getSize: Int = 0

  override def iterator: InnerSetIterator[T] = new InnerSetIterator[T](this)

  override def copy: Option[InnerSet[T]] = null

  override def clear(unused: Boolean): InnerSet[T] = this

  override def toString: String = "{ }"

}
