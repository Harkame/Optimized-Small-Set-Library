package scala.implementation

object InnerSet_3
{
    def apply[T](element1: T, element2: T, element3: T): InnerSet_3[T] = new InnerSet_3[T](element1, element2, element3)
}

class InnerSet_3[T](element1: T, element2: T, element3: T) extends InnerSet[T]
{

    override def addElement(p_element: T): InnerSet[T] =
    {
        if (element1.equals(p_element) || element2.equals(p_element) || element3.equals(p_element))
        {
            this
        }
        else  InnerSet_4(element1, element2, element3, p_element)
    }

    override def addUnchecked(p_element: T): InnerSet[T] = InnerSet_4(element1, element2, element3, p_element)


    override def addAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =     {
                p_innerSet.addElement(element1)
                p_innerSet.addElement(element2)
                p_innerSet.addElement(element3)
            }
    override def containsElements(p_element: T): Boolean = element1.equals(p_element) || element2.equals(p_element) || element3.equals(p_element)

    override def containsAllElements(p_innerSet: InnerSet[T]): Boolean =  p_innerSet.containsElements(element1) && p_innerSet.containsElements(element2) && p_innerSet.containsElements(element3)

    override def getElement(p_index: Int): Option[T] = p_index match{
        case 1 => Option(element1)
        case 2 => Option(element2)
        case 3 => Option(element3)
        case _ => None
    }


    override def removeElement(p_element: T): InnerSet[T] =
    {
            if(element1.equals(p_element))
         InnerSet_2(element2, element3)
                  else             if(element2.equals(p_element))
         InnerSet_2(element1, element3)
                  else             if(element3.equals(p_element))
         InnerSet_2(element1, element2)
                            else this
    }


    override def removeAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =     {
                p_innerSet.removeElement(element1)
                p_innerSet.removeElement(element2)
                p_innerSet.removeElement(element3)
            }

    override def retainAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =
    {
      var i: InnerSet[T] = this
            if(!p_innerSet.containsElements(element1)) i = i.removeElement(element1)
            if(!p_innerSet.containsElements(element2)) i = i.removeElement(element2)
            if(!p_innerSet.containsElements(element3)) i = i.removeElement(element3)
            i
    }

    override def getSize: Int = 3

    override def iterator: InnerSetIterator[T] = InnerSetIterator(this)

    override def copy: Option[InnerSet[T]] = Option(InnerSet_3(element1: T, element2: T, element3: T))

    override def clear(unused: Boolean): InnerSet[T] = new InnerSet_0
}