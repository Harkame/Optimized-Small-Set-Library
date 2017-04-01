package scala.implementation

/**
  * Created by pxl on 28/03/17.
  */
trait InnerSet[T] {

  def addElement(p_element: T): InnerSet[T]
  def addUnchecked(p_element: T): InnerSet[T]
  def addAllElements(innerSet: InnerSet[T]): InnerSet[T]

  def containsElements(p_element: T): Boolean
  def containsAllElements(innerSet: InnerSet[T]): Boolean

  def getElement(index: Int): Option[T]

  def removeElement(p_element: T): InnerSet[T]
  def removeAllElements(innerSet: InnerSet[T]): InnerSet[T]

  def retainAllElements(innerSet: InnerSet[T]): InnerSet[T]

  def getSize: Int
  def iterator: InnerSetIterator[T]
  def copy: Option[InnerSet[T]]
  def clear(unused: Boolean): InnerSet[T]
}
