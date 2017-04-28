package scala.implementation

import java.util.ArrayList


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
        return new InnerHashSet[T](this, p_element)
      }
      else add(p_element)
    }
    this
  }

  override def addUnchecked(p_element: T): InnerSet[T] =
  {
    if(getSize == maxSize){
      return new InnerHashSet[T](this, p_element)
    }
    else add(p_element)
    this
  }

  override def addAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =
  {
    val it: InnerSetIterator[T] = this.iterator
    var innerSetReturn: InnerSet[T] = p_innerSet
      while(it.hasNext){
      innerSetReturn = innerSetReturn.addElement(it.next())
    }
    innerSetReturn
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

  override def iterator: InnerSetIterator[T] = new InnerSetIterator(this)

  override def copy: Option[InnerSet[T]] = Option(new InnerArraySet(this))

  override def clear(unused: Boolean): InnerSet[T] = clear(unused)

  override def toString(): String = ???

  override def addAndPropagate(p_element: T, p_microSet: MicroSet[T]): InnerSet[T] =
  {
    if(!contains(p_element))
    {
      p_microSet.add(p_element)
      if(getSize == maxSize){
        return new InnerHashSet[T](this, p_element)
      }
      else add(p_element)
    }
    this
  }

  override def addAllAndPropagate(p_innerSet: InnerSet[T], p_microSet: MicroSet[T]): InnerSet[T] = p_innerSet.addAllAndPropagateReverse(this, p_microSet)

  override def addAllAndPropagateReverse(p_innerSet: InnerSet[T], p_microSet: MicroSet[T]): InnerSet[T] =
  {
    val it: InnerSetIterator[T] = this.iterator
    var innerSetReturn: InnerSet[T] = p_innerSet
      while(it.hasNext){
      innerSetReturn = innerSetReturn.addAndPropagate(it.next(),p_microSet)
    }
    innerSetReturn
  }
}
