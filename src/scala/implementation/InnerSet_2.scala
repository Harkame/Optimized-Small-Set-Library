package scala.implementation

object InnerSet_2
{
    def apply[T](element1: T, element2: T): InnerSet_2[T] = new InnerSet_2[T](element1, element2)
}

class InnerSet_2[T](element1: T, element2: T) extends InnerSet[T]
{

    override def addElement(p_element: T): InnerSet[T] =
    {
        if (element1.equals(p_element) || element2.equals(p_element))
        {
            this
        }
        else  new InnerSet_3(element1, element2, p_element)
    }

    override def addUnchecked(p_element: T): InnerSet[T] = InnerSet_3(element1, element2, p_element)


    override def addAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =     {
                p_innerSet.addElement(element1)
                p_innerSet.addElement(element2)
            }
    override def containsElements(p_element: T): Boolean = element1.equals(p_element) || element2.equals(p_element)

    override def containsAllElements(p_innerSet: InnerSet[T]): Boolean =  p_innerSet.containsElements(element1) && p_innerSet.containsElements(element2)

    override def getElement(p_index: Int): Option[T] = p_index match{
        case 1 => Option(element1)
        case 2 => Option(element2)
        case _ => None
    }


    override def removeElement(p_element: T): InnerSet[T] =
    {
            if(element1.equals(p_element))
         new InnerSet_1(element2)
                  else             if(element2.equals(p_element))
         new InnerSet_1(element1)
                            else this
    }


    override def removeAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =     {
                p_innerSet.removeElement(element1)
                p_innerSet.removeElement(element2)
            }

    override def retainAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =
    {
      var i: InnerSet[T] = this
            if(!p_innerSet.containsElements(element1)) i = i.removeElement(element1)
            if(!p_innerSet.containsElements(element2)) i = i.removeElement(element2)
            i
    }

    override def getSize: Int = 2

    override def iterator: InnerSetIterator[T] = new InnerSetIterator(this)

    override def copy: Option[InnerSet[T]] = Option(new InnerSet_2(element1: T, element2: T))

    override def clear(unused: Boolean): InnerSet[T] = new InnerSet_0
}