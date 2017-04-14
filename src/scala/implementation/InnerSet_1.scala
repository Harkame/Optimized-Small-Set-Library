package scala.implementation

object InnerSet_1
{
    def apply[T](element1: T): InnerSet_1[T] = new InnerSet_1[T](element1)
}

class InnerSet_1[T](element1: T) extends AbstractInnerSet[T]
{

    override def addElement(p_element: T): InnerSet[T] =
    {
        if (element1.equals(p_element))
        {
            this
        }
        else  InnerSet_2(element1, p_element)
    }

    override def addUnchecked(p_element: T): InnerSet[T] = InnerSet_2(element1, p_element)


    override def addAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =  p_innerSet.addElement(element1)
    override def containsElement(p_element: Object): Boolean = element1.equals(p_element)
    override def containsAllElements(p_innerSet: InnerSet[T]): Boolean =  p_innerSet.containsElement(element1.asInstanceOf[Object])

    override def getElement(p_index: Int): Option[T] = p_index match{
        case 1 => Option(element1)
        case _ => None
    }


    override def removeElement(p_element: Object): InnerSet[T] =
    {
            if(element1.equals(p_element))
         new InnerSet_0
                        else this
    }

    override def removeAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =  p_innerSet.removeElement(element1.asInstanceOf[Object])

    override def retainAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =
    {
      var i: InnerSet[T] = this
            if(!p_innerSet.containsElement(element1.asInstanceOf[Object])) i = i.removeElement(element1.asInstanceOf[Object])
            i
    }

    override def getSize: Int = 1

    override def iterator: InnerSetIterator[T] = InnerSetIterator(this)

    override def copy: Option[InnerSet[T]] = Option(InnerSet_1(element1: T))

    override def clear(unused: Boolean): InnerSet[T] = new InnerSet_0

    override def toString : String = "{ " + element1 + " }"
}