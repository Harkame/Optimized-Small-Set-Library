package scala.implementation


import java.util.HashSet
import java.util.Iterator

/**
  * Created by pxl on 29/03/17.
  */

object InnerHashSet
{
  def apply[T](innerSet: InnerSet[T]): InnerHashSet[T] = new InnerHashSet[T](innerSet)
}

 class InnerHashSet[T] extends HashSet[T] with InnerSet[T]{

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

  override def getElement(index: Int): Option[T] = ???

  override def removeElement(p_element: T): InnerSet[T] =
  {
    remove(p_element)
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

  override def retainAllElements(p_innerSet: InnerSet[T]): InnerSet[T] = ???

  override def getSize: Int = ???

  override def copy: InnerSet[T] =
  {
    val innerSet: InnerSet[T] = this
    return InnerHashSet(innerSet)
  }

  override def clear(unused: Boolean): InnerSet[T] = this.clear(unused)
}
