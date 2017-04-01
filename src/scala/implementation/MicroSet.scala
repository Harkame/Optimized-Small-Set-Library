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
    var oldInnerSet: InnerSet[T] = innerSet
    innerSet = innerSet.addElement(element)
    oldInnerSet.getSize + 1 != innerSet.getSize
  }

  def AddAll(microSet: MicroSet[T]): Boolean =
  {
    var oldInnerSet: InnerSet[T] = innerSet
    innerSet = microSet.innerSet.addAllElements(oldInnerSet)
    innerSet.getSize != microSet.innerSet.getSize
  }

  def remove(element: T): Boolean =
  {
    var oldInnerSet: InnerSet[T] = innerSet
    innerSet = innerSet.removeElement(element)
    (oldInnerSet.getSize -1) != innerSet.getSize
  }

  def removeAll(microSet: MicroSet[T]): Boolean =
  {
    var oldInnerSet: InnerSet[T] = innerSet
    innerSet = microSet.innerSet.removeAllElements(oldInnerSet)
    innerSet.getSize != microSet.innerSet.getSize
  }

  def contains(element: T): Boolean = innerSet.containsElements(element)

  def containsAll(microSet: MicroSet[T]): Boolean = microSet.innerSet.containsAllElements(innerSet)

  def retainsAll(microSet: MicroSet[T]): Boolean =
  {
    var oldInnerSet: InnerSet[T] = innerSet
    innerSet = microSet.innerSet.retainAllElements(innerSet)
    innerSet.getSize != microSet.innerSet.getSize
  }

  def size(): Int = innerSet.getSize

  def isEmpty(): Boolean = innerSet.getSize == 0

  def clear() = innerSet.clear(true)

  override def toString: String = "MicroSet { " + "innerSet = " + innerSet + " }" + "\n" + innerSet.toString

  override def removeAll(c: util.Collection[_]): Boolean = ??? //TODO

  override def retainAll(c: util.Collection[_]): Boolean = ??? //TODO

  override def toArray: Array[AnyRef] = ??? //TODO

  override def toArray[T](a: Array[T]): Array[T] = ??? //TODO

  override def remove(o: scala.Any): Boolean = ??? //TODO

  override def contains(o: scala.Any): Boolean = ??? //TODO

  override def iterator(): util.Iterator[T] = ??? //TODO

  override def addAll(c: util.Collection[_ <: T]): Boolean = ??? //TODO

  override def containsAll(c: util.Collection[_]): Boolean = ??? //TODO
}
