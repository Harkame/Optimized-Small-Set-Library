package scala.implementation

/**
  * Created by pxl on 28/03/17.
  */


class MicroSet[T] {

  var innerSet: InnerSet[T]

  def apply[T] = innerSet = new InnerSet_0

  def add(element: T): Boolean =
  {
    var oldInnerSet: InnerSet[T] = innerSet
    innerSet = innerSet.addElement(element)
    return oldInnerSet.getSize + 1 != innerSet.getSize
  }

  def AddAll(microSet: MicroSet[T]): Boolean =
  {
    var oldInnerSet: InnerSet[T] = innerSet
    innerSet = microSet.innerSet.addAllElements(oldInnerSet)
    return innerSet.getSize != microSet.innerSet.getSize
  }

  def remove(element: T): Boolean =
  {
    var oldInnerSet: InnerSet[T] = innerSet
    innerSet = innerSet.removeElement(element)
    return (oldInnerSet.getSize -1) != innerSet.getSize
  }

  def removeAll(microSet: MicroSet[T]): Boolean =
  {
    var oldInnerSet: InnerSet[T] = innerSet
    innerSet = microSet.innerSet.removeAllElements(oldInnerSet)
    return innerSet.getSize != microSet.innerSet.getSize
  }

  def contains(element: T): Boolean = innerSet.containsElements(element)

  def containsAll(microSet: MicroSet[T]): Boolean = microSet.innerSet.containsAllElements(innerSet)

  def retainsAll(microSet: MicroSet[T]): Boolean =
  {
    var oldInnerSet: InnerSet[T] = innerSet
    innerSet = microSet.innerSet.retainAllElements(innerSet)
    return innerSet.getSize != microSet.innerSet.getSize
  }

  def size(): Int = innerSet.getSize

  def isEmpty(): Boolean = innerSet.getSize == 0

  def clear() = innerSet = innerSet.clear(true)

}
