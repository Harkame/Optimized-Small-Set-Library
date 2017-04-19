package scala.implementation

import java.util.ArrayList

object InnerArraySet{
  def apply[T](p_innerSet:InnerSet[T]): InnerArraySet[T] = new InnerArraySet(p_innerSet)
}

class InnerArraySet[T] extends ArrayList[T] with InnerSet[T] {

  private val maxSize = 20

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
    if(!contains(p_element))
    {
      if(getSize == maxSize){
        return InnerHashSet[T](this, p_element)
      }
      else add(p_element)
    }
    this
  }

  override def addUnchecked(p_element: T): InnerSet[T] =
  {
    if(getSize == maxSize){
      return InnerHashSet[T](this, p_element)
    }
    else add(p_element)
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

  override def containsElement(p_element: Object): Boolean = contains(p_element)

  override def containsAllElements(p_innerSet: InnerSet[T]): Boolean =
  {
    val it: InnerSetIterator[T] = p_innerSet.iterator
    while(it.hasNext){
      if(!contains(it.next())) return false
    }
    true
  }

  override def getElement(index: Int): Option[T] = Option(get(index))

  override def removeElement(p_element: Object): InnerSet[T] =
  {
    if(containsElement(p_element)) remove(p_element)
    this
  }

  override def removeAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =
  {
    val it: InnerSetIterator[T] = p_innerSet.iterator
    while(it.hasNext){
      if(contains(it.next())) remove(it.next())
    }
    this
  }

  override def retainAllElements(p_innerSet: InnerSet[T]): InnerSet[T] = ??? //TODO

  override def getSize: Int = size()

  override def iterator: InnerSetIterator[T] = InnerSetIterator(this)

  override def copy: Option[InnerSet[T]] = Option(InnerArraySet(this))

  override def clear(unused: Boolean): InnerSet[T] = clear(unused)

  override def toString(): String = ???
}
