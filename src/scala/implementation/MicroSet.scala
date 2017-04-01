package scala.implementation

import java.util
import java.util.Set

object MicroSet {
  def apply[T]: MicroSet[T] = new MicroSet[T]
  def apply[T](innerSet: InnerSet[T]): MicroSet[T] = new MicroSet[T](innerSet)
  def apply[T](microSet: MicroSet[T]): MicroSet[T] = new MicroSet[T](microSet)
}

class MicroSet[T]() extends Set[T] {

  var innerSet: InnerSet[T] = new InnerSet_0

  def this(microSet: MicroSet[T]) =
  {
    this
    innerSet = microSet.innerSet.copy.get
  }

  def this(p_innerSet: InnerSet[T]) =
  {
    this
    innerSet = p_innerSet
  }

  def add(element: T): Boolean =
  {
    val oldInnerSet: InnerSet[T] = innerSet
    innerSet = innerSet.addElement(element)
    oldInnerSet.getSize + 1 != innerSet.getSize
  }

  def AddAll(microSet: MicroSet[T]): Boolean =
  {
    val oldInnerSet: InnerSet[T] = innerSet
    innerSet = microSet.innerSet.addAllElements(oldInnerSet)
    innerSet.getSize != microSet.innerSet.getSize
  }

  override def addAll(c: util.Collection[_ <: T]): Boolean =
  {
    val oldInnerSet = this.innerSet
    for (el <- c) {
      innerSet.addElement(el)
    }
    innerSet.getSize != oldInnerSet.getSize
  }

  def remove(element: Object): Boolean =
  {
    val oldInnerSet: InnerSet[T] = innerSet
    innerSet = innerSet.removeElement(element)
    (oldInnerSet.getSize -1) != innerSet.getSize
  }

  def removeAll(microSet: MicroSet[T]): Boolean =
  {
    val oldInnerSet: InnerSet[T] = innerSet
    innerSet = microSet.innerSet.removeAllElements(oldInnerSet)
    innerSet.getSize != microSet.innerSet.getSize
  }

  override def removeAll(c: util.Collection[_]): Boolean =
  {
    val oldInnerSet = innerSet
    for (el <- c) {
      if(innerSet.containsElement(el)) innerSet.removeElement(el)
    }
    innerSet.getSize != oldInnerSet.getSize
  }

  override def contains(element: Object): Boolean = innerSet.containsElement(element)

  def containsAll(microSet: MicroSet[T]): Boolean = microSet.innerSet.containsAllElements(innerSet)

  override def containsAll(c: util.Collection[_]): Boolean =
  {
    for (el <- c) {
      if(!innerSet.containsElement(el)) false
    }
    true
  }

  def retainsAll(microSet: MicroSet[T]): Boolean =
  {
    var oldInnerSet: InnerSet[T] = innerSet
    innerSet = microSet.innerSet.retainAllElements(innerSet)
    innerSet.getSize != microSet.innerSet.getSize
  }

  override def retainAll(c: util.Collection[_]): Boolean =
  {
    val oldInnerSet: InnerSet[T] = innerSet
    this.innerSet = InnerSet_0[T]
    for (el <- c) {
      if (oldInnerSet.containsElement(el)) innerSet = innerSet.addElement(el)
    }
    innerSet.getSize != oldInnerSet.getSize
  }

  def size(): Int = innerSet.getSize

  def isEmpty(): Boolean = innerSet.getSize == 0

  def clear() = innerSet.clear(true)

  override def iterator(): util.Iterator[T] = ??? //TODO

  override def toString: String = "MicroSet { " + "innerSet = " + innerSet + " }" + "\n" + innerSet.toString

  override def toArray: Array[AnyRef] = ??? //TODO

  override def toArray[T](a: Array[T]): Array[T] = ??? //TODO

}
