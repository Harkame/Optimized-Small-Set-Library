package scala.implementation


class InnerSet_7[T](protected val element1: T, protected val element2: T, protected val element3: T, protected val element4: T, protected val element5: T, protected val element6: T, protected val element7: T) extends AbstractInnerSet[T]
{

    def this(p_innerSet: InnerSet_7[T]) = this(p_innerSet.element1 , p_innerSet.element2 , p_innerSet.element3 , p_innerSet.element4 , p_innerSet.element5 , p_innerSet.element6 , p_innerSet.element7 )
    override def addElement(p_element: T): InnerSet[T] =
    {
        if (element1.equals(p_element) || element2.equals(p_element) || element3.equals(p_element) || element4.equals(p_element) || element5.equals(p_element) || element6.equals(p_element) || element7.equals(p_element))
        {
            this
        }
        else  new InnerSet_8(element1, element2, element3, element4, element5, element6, element7, p_element)
    }

    override def addUnchecked(p_element: T): InnerSet[T] =  new InnerSet_8(element1, element2, element3, element4, element5, element6, element7, p_element)

    override def addAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =  p_innerSet .addElement(element1) .addElement(element2) .addElement(element3) .addElement(element4) .addElement(element5) .addElement(element6) .addElement(element7)

    override def containsElement(p_element: Object): Boolean = element1.equals(p_element) || element2.equals(p_element) || element3.equals(p_element) || element4.equals(p_element) || element5.equals(p_element) || element6.equals(p_element) || element7.equals(p_element)

    override def containsAllElements(p_innerSet: InnerSet[T]): Boolean =  p_innerSet.containsElement(element1.asInstanceOf[Object]) && p_innerSet.containsElement(element2.asInstanceOf[Object]) && p_innerSet.containsElement(element3.asInstanceOf[Object]) && p_innerSet.containsElement(element4.asInstanceOf[Object]) && p_innerSet.containsElement(element5.asInstanceOf[Object]) && p_innerSet.containsElement(element6.asInstanceOf[Object]) && p_innerSet.containsElement(element7.asInstanceOf[Object])

    override def getElement(p_index: Int): Option[T] = p_index match{
        case 1 => Some(element1)
        case 2 => Some(element2)
        case 3 => Some(element3)
        case 4 => Some(element4)
        case 5 => Some(element5)
        case 6 => Some(element6)
        case 7 => Some(element7)
        case _ => None
    }


    override def removeElement(p_element: Object): InnerSet[T] =
    {
            if(element1.equals(p_element))
         new InnerSet_6(element2, element3, element4, element5, element6, element7)
                  else             if(element2.equals(p_element))
         new InnerSet_6(element1, element3, element4, element5, element6, element7)
                  else             if(element3.equals(p_element))
         new InnerSet_6(element1, element2, element4, element5, element6, element7)
                  else             if(element4.equals(p_element))
         new InnerSet_6(element1, element2, element3, element5, element6, element7)
                  else             if(element5.equals(p_element))
         new InnerSet_6(element1, element2, element3, element4, element6, element7)
                  else             if(element6.equals(p_element))
         new InnerSet_6(element1, element2, element3, element4, element5, element7)
                  else             if(element7.equals(p_element))
         new InnerSet_6(element1, element2, element3, element4, element5, element6)
                            else this
    }

    override def removeAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =  p_innerSet .removeElement(element1.asInstanceOf[Object]) .removeElement(element2.asInstanceOf[Object]) .removeElement(element3.asInstanceOf[Object]) .removeElement(element4.asInstanceOf[Object]) .removeElement(element5.asInstanceOf[Object]) .removeElement(element6.asInstanceOf[Object]) .removeElement(element7.asInstanceOf[Object])

    override def retainAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =
    {
      var i: InnerSet[T] = this
            if(!p_innerSet.containsElement(element1.asInstanceOf[Object])) i = i.removeElement(element1.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element2.asInstanceOf[Object])) i = i.removeElement(element2.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element3.asInstanceOf[Object])) i = i.removeElement(element3.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element4.asInstanceOf[Object])) i = i.removeElement(element4.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element5.asInstanceOf[Object])) i = i.removeElement(element5.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element6.asInstanceOf[Object])) i = i.removeElement(element6.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element7.asInstanceOf[Object])) i = i.removeElement(element7.asInstanceOf[Object])
            i
    }

    override def getSize: Int = 7

    override def iterator: InnerSetIterator[T] = new InnerSetIterator(this)

    override def copy: InnerSet[T] = this

    override def clear(unused: Boolean): InnerSet[T] = InnerSet_0[T]

    override def toString : String = "{ " + element1 + ", " + element2 + ", " + element3 + ", " + element4 + ", " + element5 + ", " + element6 + ", " + element7 + " }"

    override def addAndPropagate(p_element: T, p_microSet: MicroSet[T]): InnerSet[T] =
    {
        if (element1.equals(p_element) || element2.equals(p_element) || element3.equals(p_element) || element4.equals(p_element) || element5.equals(p_element) || element6.equals(p_element) || element7.equals(p_element))
        {
            this
        }
        else         {
            p_microSet.add(p_element)
            new InnerSet_8(element1, element2, element3, element4, element5, element6, element7, p_element)
        }    }

    override def addAllAndPropagate(p_innerSet: InnerSet[T], p_microSet: MicroSet[T]): InnerSet[T] = p_innerSet.addAllAndPropagateReverse(this, p_microSet)

    override def addAllAndPropagateReverse(p_innerSet: InnerSet[T], p_microSet: MicroSet[T]): InnerSet[T] =  p_innerSet .addAndPropagate(element1,p_microSet) .addAndPropagate(element2,p_microSet) .addAndPropagate(element3,p_microSet) .addAndPropagate(element4,p_microSet) .addAndPropagate(element5,p_microSet) .addAndPropagate(element6,p_microSet) .addAndPropagate(element7,p_microSet)
}