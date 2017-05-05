package scala.implementation

import java.util.HashSet



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

  def this(p_innerSet: InnerSet[T], p_element: T) =
  {
    this
    val it: InnerSetIterator[T] = p_innerSet.iterator
    while(it.hasNext)
    {
      add(it.next())
    }
    add(p_element)

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

   override def addAndPropagate(p_element: T, p_microSet: MicroSet[T]): InnerSet[T] =
   {
     if(!contains(p_element))
     {
       p_microSet.add(p_element)
       add(p_element)
     }
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

   override def containsElement(p_element: Object): Boolean = contains(p_element)

  override def containsAllElements(p_innerSet: InnerSet[T]): Boolean =
  {
    val it: InnerSetIterator[T] = p_innerSet.iterator
    while(it.hasNext){
      if(!contains(it.next())) return false
    }
    true
  }

  override def getElement(index: Int): Option[T] = ??? //TODO

  override def removeElement(p_element: Object): InnerSet[T] =
  {
    remove(p_element)
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

  override def getSize: Int = ??? //TODO

   override def iterator: InnerSetIterator[T] = new InnerSetIterator(this)

  override def copy: Option[InnerHashSet[T]] =
  {
    Some(new InnerHashSet(this))
  }

  override def clear(unused: Boolean): InnerSet[T] = this.clear(unused)


 }
