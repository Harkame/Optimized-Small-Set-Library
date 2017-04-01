package scala.implementation

import java.util.ArrayList

object InnerArraySet{
  def apply[T](p_innerSet:InnerSet[T]): InnerArraySet[T] = new InnerArraySet(p_innerSet)
}

class InnerArraySet[T] extends ArrayList[T] with InnerSet[T] {

  def this(p_innerSet: InnerSet[T]) =
  {
    this
    val it: InnerSetIterator[T] = p_innerSet.iterator
    while(it.hasNext)
    {
      add(it.next())
    }
  }

  override def addElement(p_element: T): InnerSet[T] =
  {
    if(!contains(p_element)) add(p_element)
    this
  }

  override def addUnchecked(p_element: T): InnerSet[T] =
  {
    add(p_element)
    this
  }

  override def addAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =
  {
    val it: InnerSetIterator[T] = p_innerSet.iterator
    while(it.hasNext){
      addElement(it.next())
    }
    this
  }

  override def containsElements(p_element: T): Boolean = contains(p_element)

  override def containsAllElements(p_innerSet: InnerSet[T]): Boolean =
  {
    val it: InnerSetIterator[T] = p_innerSet.iterator
    while(it.hasNext){
      if(!containsElements(it.next())) false
    }
    true
  }

  override def getElement(index: Int): Option[T] = Option(get(index))

  override def removeElement(p_element: T): InnerSet[T] =
  {
    if(containsElements(p_element)) remove(p_element)
    this
  }

  override def removeAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =
  {
    val it: InnerSetIterator[T] = p_innerSet.iterator
    while(it.hasNext){
      if(containsElements(it.next())) removeElement(it.next())
    }
    this
  }

  override def retainAllElements(p_innerSet: InnerSet[T]): InnerSet[T] = ??? //TODO

  override def getSize: Int = size()

  override def copy: Option[InnerSet[T]] = Option(InnerArraySet(this))

  override def clear(unused: Boolean): InnerSet[T] = clear(unused)
}
