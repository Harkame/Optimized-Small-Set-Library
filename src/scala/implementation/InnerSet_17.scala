package scala.implementation


class InnerSet_17[T](protected val element1: T, protected val element2: T, protected val element3: T, protected val element4: T, protected val element5: T, protected val element6: T, protected val element7: T, protected val element8: T, protected val element9: T, protected val element10: T, protected val element11: T, protected val element12: T, protected val element13: T, protected val element14: T, protected val element15: T, protected val element16: T, protected val element17: T) extends AbstractInnerSet[T]
{

    def this(p_innerSet: InnerSet_17[T]) = this(p_innerSet.element1 , p_innerSet.element2 , p_innerSet.element3 , p_innerSet.element4 , p_innerSet.element5 , p_innerSet.element6 , p_innerSet.element7 , p_innerSet.element8 , p_innerSet.element9 , p_innerSet.element10 , p_innerSet.element11 , p_innerSet.element12 , p_innerSet.element13 , p_innerSet.element14 , p_innerSet.element15 , p_innerSet.element16 , p_innerSet.element17 )
    override def addElement(p_element: T): InnerSet[T] =
    {
        if (element1.equals(p_element) || element2.equals(p_element) || element3.equals(p_element) || element4.equals(p_element) || element5.equals(p_element) || element6.equals(p_element) || element7.equals(p_element) || element8.equals(p_element) || element9.equals(p_element) || element10.equals(p_element) || element11.equals(p_element) || element12.equals(p_element) || element13.equals(p_element) || element14.equals(p_element) || element15.equals(p_element) || element16.equals(p_element) || element17.equals(p_element))
        {
            this
        }
        else  new InnerSet_18(element1, element2, element3, element4, element5, element6, element7, element8, element9, element10, element11, element12, element13, element14, element15, element16, element17, p_element)
    }

    override def addUnchecked(p_element: T): InnerSet[T] =  new InnerSet_18(element1, element2, element3, element4, element5, element6, element7, element8, element9, element10, element11, element12, element13, element14, element15, element16, element17, p_element)

    override def addAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =  p_innerSet .addElement(element1) .addElement(element2) .addElement(element3) .addElement(element4) .addElement(element5) .addElement(element6) .addElement(element7) .addElement(element8) .addElement(element9) .addElement(element10) .addElement(element11) .addElement(element12) .addElement(element13) .addElement(element14) .addElement(element15) .addElement(element16) .addElement(element17)

    override def containsElement(p_element: Object): Boolean = element1.equals(p_element) || element2.equals(p_element) || element3.equals(p_element) || element4.equals(p_element) || element5.equals(p_element) || element6.equals(p_element) || element7.equals(p_element) || element8.equals(p_element) || element9.equals(p_element) || element10.equals(p_element) || element11.equals(p_element) || element12.equals(p_element) || element13.equals(p_element) || element14.equals(p_element) || element15.equals(p_element) || element16.equals(p_element) || element17.equals(p_element)

    override def containsAllElements(p_innerSet: InnerSet[T]): Boolean =  p_innerSet.containsElement(element1.asInstanceOf[Object]) && p_innerSet.containsElement(element2.asInstanceOf[Object]) && p_innerSet.containsElement(element3.asInstanceOf[Object]) && p_innerSet.containsElement(element4.asInstanceOf[Object]) && p_innerSet.containsElement(element5.asInstanceOf[Object]) && p_innerSet.containsElement(element6.asInstanceOf[Object]) && p_innerSet.containsElement(element7.asInstanceOf[Object]) && p_innerSet.containsElement(element8.asInstanceOf[Object]) && p_innerSet.containsElement(element9.asInstanceOf[Object]) && p_innerSet.containsElement(element10.asInstanceOf[Object]) && p_innerSet.containsElement(element11.asInstanceOf[Object]) && p_innerSet.containsElement(element12.asInstanceOf[Object]) && p_innerSet.containsElement(element13.asInstanceOf[Object]) && p_innerSet.containsElement(element14.asInstanceOf[Object]) && p_innerSet.containsElement(element15.asInstanceOf[Object]) && p_innerSet.containsElement(element16.asInstanceOf[Object]) && p_innerSet.containsElement(element17.asInstanceOf[Object])

    override def getElement(p_index: Int): Option[T] = p_index match{
        case 1 => Some(element1)
        case 2 => Some(element2)
        case 3 => Some(element3)
        case 4 => Some(element4)
        case 5 => Some(element5)
        case 6 => Some(element6)
        case 7 => Some(element7)
        case 8 => Some(element8)
        case 9 => Some(element9)
        case 10 => Some(element10)
        case 11 => Some(element11)
        case 12 => Some(element12)
        case 13 => Some(element13)
        case 14 => Some(element14)
        case 15 => Some(element15)
        case 16 => Some(element16)
        case 17 => Some(element17)
        case _ => None
    }


    override def removeElement(p_element: Object): InnerSet[T] =
    {
            if(element1.equals(p_element))
         new InnerSet_16(element2, element3, element4, element5, element6, element7, element8, element9, element10, element11, element12, element13, element14, element15, element16, element17)
                  else             if(element2.equals(p_element))
         new InnerSet_16(element1, element3, element4, element5, element6, element7, element8, element9, element10, element11, element12, element13, element14, element15, element16, element17)
                  else             if(element3.equals(p_element))
         new InnerSet_16(element1, element2, element4, element5, element6, element7, element8, element9, element10, element11, element12, element13, element14, element15, element16, element17)
                  else             if(element4.equals(p_element))
         new InnerSet_16(element1, element2, element3, element5, element6, element7, element8, element9, element10, element11, element12, element13, element14, element15, element16, element17)
                  else             if(element5.equals(p_element))
         new InnerSet_16(element1, element2, element3, element4, element6, element7, element8, element9, element10, element11, element12, element13, element14, element15, element16, element17)
                  else             if(element6.equals(p_element))
         new InnerSet_16(element1, element2, element3, element4, element5, element7, element8, element9, element10, element11, element12, element13, element14, element15, element16, element17)
                  else             if(element7.equals(p_element))
         new InnerSet_16(element1, element2, element3, element4, element5, element6, element8, element9, element10, element11, element12, element13, element14, element15, element16, element17)
                  else             if(element8.equals(p_element))
         new InnerSet_16(element1, element2, element3, element4, element5, element6, element7, element9, element10, element11, element12, element13, element14, element15, element16, element17)
                  else             if(element9.equals(p_element))
         new InnerSet_16(element1, element2, element3, element4, element5, element6, element7, element8, element10, element11, element12, element13, element14, element15, element16, element17)
                  else             if(element10.equals(p_element))
         new InnerSet_16(element1, element2, element3, element4, element5, element6, element7, element8, element9, element11, element12, element13, element14, element15, element16, element17)
                  else             if(element11.equals(p_element))
         new InnerSet_16(element1, element2, element3, element4, element5, element6, element7, element8, element9, element10, element12, element13, element14, element15, element16, element17)
                  else             if(element12.equals(p_element))
         new InnerSet_16(element1, element2, element3, element4, element5, element6, element7, element8, element9, element10, element11, element13, element14, element15, element16, element17)
                  else             if(element13.equals(p_element))
         new InnerSet_16(element1, element2, element3, element4, element5, element6, element7, element8, element9, element10, element11, element12, element14, element15, element16, element17)
                  else             if(element14.equals(p_element))
         new InnerSet_16(element1, element2, element3, element4, element5, element6, element7, element8, element9, element10, element11, element12, element13, element15, element16, element17)
                  else             if(element15.equals(p_element))
         new InnerSet_16(element1, element2, element3, element4, element5, element6, element7, element8, element9, element10, element11, element12, element13, element14, element16, element17)
                  else             if(element16.equals(p_element))
         new InnerSet_16(element1, element2, element3, element4, element5, element6, element7, element8, element9, element10, element11, element12, element13, element14, element15, element17)
                  else             if(element17.equals(p_element))
         new InnerSet_16(element1, element2, element3, element4, element5, element6, element7, element8, element9, element10, element11, element12, element13, element14, element15, element16)
                            else this
    }

    override def removeAllElements(p_innerSet: InnerSet[T]): InnerSet[T] =  p_innerSet .removeElement(element1.asInstanceOf[Object]) .removeElement(element2.asInstanceOf[Object]) .removeElement(element3.asInstanceOf[Object]) .removeElement(element4.asInstanceOf[Object]) .removeElement(element5.asInstanceOf[Object]) .removeElement(element6.asInstanceOf[Object]) .removeElement(element7.asInstanceOf[Object]) .removeElement(element8.asInstanceOf[Object]) .removeElement(element9.asInstanceOf[Object]) .removeElement(element10.asInstanceOf[Object]) .removeElement(element11.asInstanceOf[Object]) .removeElement(element12.asInstanceOf[Object]) .removeElement(element13.asInstanceOf[Object]) .removeElement(element14.asInstanceOf[Object]) .removeElement(element15.asInstanceOf[Object]) .removeElement(element16.asInstanceOf[Object]) .removeElement(element17.asInstanceOf[Object])

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
            if(!p_innerSet.containsElement(element8.asInstanceOf[Object])) i = i.removeElement(element8.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element9.asInstanceOf[Object])) i = i.removeElement(element9.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element10.asInstanceOf[Object])) i = i.removeElement(element10.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element11.asInstanceOf[Object])) i = i.removeElement(element11.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element12.asInstanceOf[Object])) i = i.removeElement(element12.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element13.asInstanceOf[Object])) i = i.removeElement(element13.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element14.asInstanceOf[Object])) i = i.removeElement(element14.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element15.asInstanceOf[Object])) i = i.removeElement(element15.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element16.asInstanceOf[Object])) i = i.removeElement(element16.asInstanceOf[Object])
            if(!p_innerSet.containsElement(element17.asInstanceOf[Object])) i = i.removeElement(element17.asInstanceOf[Object])
            i
    }

    override def getSize: Int = 17

    override def iterator: InnerSetIterator[T] = new InnerSetIterator(this)

    override def copy: InnerSet[T] = this

    override def clear(unused: Boolean): InnerSet[T] = InnerSet_0[T]

    override def toString : String = "{ " + element1 + ", " + element2 + ", " + element3 + ", " + element4 + ", " + element5 + ", " + element6 + ", " + element7 + ", " + element8 + ", " + element9 + ", " + element10 + ", " + element11 + ", " + element12 + ", " + element13 + ", " + element14 + ", " + element15 + ", " + element16 + ", " + element17 + " }"

    override def addAndPropagate(p_element: T, p_microSet: MicroSet[T]): InnerSet[T] =
    {
        if (element1.equals(p_element) || element2.equals(p_element) || element3.equals(p_element) || element4.equals(p_element) || element5.equals(p_element) || element6.equals(p_element) || element7.equals(p_element) || element8.equals(p_element) || element9.equals(p_element) || element10.equals(p_element) || element11.equals(p_element) || element12.equals(p_element) || element13.equals(p_element) || element14.equals(p_element) || element15.equals(p_element) || element16.equals(p_element) || element17.equals(p_element))
        {
            this
        }
        else         {
            p_microSet.add(p_element)
            new InnerSet_18(element1, element2, element3, element4, element5, element6, element7, element8, element9, element10, element11, element12, element13, element14, element15, element16, element17, p_element)
        }    }

    override def addAllAndPropagate(p_innerSet: InnerSet[T], p_microSet: MicroSet[T]): InnerSet[T] = p_innerSet.addAllAndPropagateReverse(this, p_microSet)

    override def addAllAndPropagateReverse(p_innerSet: InnerSet[T], p_microSet: MicroSet[T]): InnerSet[T] =  p_innerSet .addAndPropagate(element1,p_microSet) .addAndPropagate(element2,p_microSet) .addAndPropagate(element3,p_microSet) .addAndPropagate(element4,p_microSet) .addAndPropagate(element5,p_microSet) .addAndPropagate(element6,p_microSet) .addAndPropagate(element7,p_microSet) .addAndPropagate(element8,p_microSet) .addAndPropagate(element9,p_microSet) .addAndPropagate(element10,p_microSet) .addAndPropagate(element11,p_microSet) .addAndPropagate(element12,p_microSet) .addAndPropagate(element13,p_microSet) .addAndPropagate(element14,p_microSet) .addAndPropagate(element15,p_microSet) .addAndPropagate(element16,p_microSet) .addAndPropagate(element17,p_microSet)
}