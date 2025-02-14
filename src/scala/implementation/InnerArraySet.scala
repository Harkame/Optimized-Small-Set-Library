package scala.implementation

import java.util.ArrayList

object InnerArraySet
{
  private val maxSize = 20
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
    if(!contains(p_element))
    {
      if(getSize == InnerArraySet.maxSize){
        return new InnerHashSet[T](this, p_element)
      }
      else add(p_element)
    }
    this
  }

  override def addUnchecked(p_element: T): InnerSet[T] =
  {
    if(getSize == InnerArraySet.maxSize){
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
    var index = 0
    while (index < size) {
        if (p_element == get(index)) {
          set(index, get(size - 1))
          remove(size - 1)
        }
        index += 1
    }
    this
  }

  override def removeAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =
  {
    val it: InnerSetIterator[T] = p_innerSet.iterator
    while(it.hasNext){
      removeElement(it.next().asInstanceOf[Object])
    }
    this
  }

  override def retainAllElements(p_innerSet: InnerSet[T]): InnerSet[T] = ??? //TODO

  override def getSize: Int = size()

  override def iterator: InnerSetIterator[T] = new InnerSetIterator(this)

  override def copy: InnerSet[T] = new InnerArraySet(this)

  override def clear(unused: Boolean): InnerSet[T] = clear(unused)

  override def toString(): String =  "InnerArraySet : "+ this.toString()

  override def addAndPropagate(p_element: T, p_microSet: MicroSet[T]): InnerSet[T] =
  {
    if(!contains(p_element))
    {
      p_microSet.add(p_element)
      if(getSize == InnerArraySet.maxSize){
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
