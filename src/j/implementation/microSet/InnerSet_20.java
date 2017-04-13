package j.implementation.microSet;

import java.util.Iterator;

public class InnerSet_20 <T> extends AbstractInnerSet<T>
{
        protected T element_1;
        protected T element_2;
        protected T element_3;
        protected T element_4;
        protected T element_5;
        protected T element_6;
        protected T element_7;
        protected T element_8;
        protected T element_9;
        protected T element_10;
        protected T element_11;
        protected T element_12;
        protected T element_13;
        protected T element_14;
        protected T element_15;
        protected T element_16;
        protected T element_17;
        protected T element_18;
        protected T element_19;
        protected T element_20;
        
    public InnerSet_20(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5, T p_element_6, T p_element_7, T p_element_8, T p_element_9, T p_element_10, T p_element_11, T p_element_12, T p_element_13, T p_element_14, T p_element_15, T p_element_16, T p_element_17, T p_element_18, T p_element_19, T p_element_20)
    {
                element_1 = p_element_1;
                element_2 = p_element_2;
                element_3 = p_element_3;
                element_4 = p_element_4;
                element_5 = p_element_5;
                element_6 = p_element_6;
                element_7 = p_element_7;
                element_8 = p_element_8;
                element_9 = p_element_9;
                element_10 = p_element_10;
                element_11 = p_element_11;
                element_12 = p_element_12;
                element_13 = p_element_13;
                element_14 = p_element_14;
                element_15 = p_element_15;
                element_16 = p_element_16;
                element_17 = p_element_17;
                element_18 = p_element_18;
                element_19 = p_element_19;
                element_20 = p_element_20;
            }

    public InnerSet_20(InnerSet_20<T> i)
    {
            element_1 = i.element_1;
            element_2 = i.element_2;
            element_3 = i.element_3;
            element_4 = i.element_4;
            element_5 = i.element_5;
            element_6 = i.element_6;
            element_7 = i.element_7;
            element_8 = i.element_8;
            element_9 = i.element_9;
            element_10 = i.element_10;
            element_11 = i.element_11;
            element_12 = i.element_12;
            element_13 = i.element_13;
            element_14 = i.element_14;
            element_15 = i.element_15;
            element_16 = i.element_16;
            element_17 = i.element_17;
            element_18 = i.element_18;
            element_19 = i.element_19;
            element_20 = i.element_20;
        }

    public InnerSet_20<T> copy() {
        return new InnerSet_20(this);
    }

    public InnerSet_20(InnerSet_19<T> i, T el)
    {
            element_1 = i.element_1;            element_2 = i.element_2;            element_3 = i.element_3;            element_4 = i.element_4;            element_5 = i.element_5;            element_6 = i.element_6;            element_7 = i.element_7;            element_8 = i.element_8;            element_9 = i.element_9;            element_10 = i.element_10;            element_11 = i.element_11;            element_12 = i.element_12;            element_13 = i.element_13;            element_14 = i.element_14;            element_15 = i.element_15;            element_16 = i.element_16;            element_17 = i.element_17;            element_18 = i.element_18;            element_19 = i.element_19;                    element_20 = el;
    }
    
    @Override
    public InnerSet<T> addElement(T p_element)
    {
        if(element_1.equals(p_element) || element_2.equals(p_element) || element_3.equals(p_element) || element_4.equals(p_element) || element_5.equals(p_element) || element_6.equals(p_element) || element_7.equals(p_element) || element_8.equals(p_element) || element_9.equals(p_element) || element_10.equals(p_element) || element_11.equals(p_element) || element_12.equals(p_element) || element_13.equals(p_element) || element_14.equals(p_element) || element_15.equals(p_element) || element_16.equals(p_element) || element_17.equals(p_element) || element_18.equals(p_element) || element_19.equals(p_element) || element_20.equals(p_element))
            return this;
        else
            return new InnerHashSet<>(this);    }

    @Override
    public InnerSet<T> addUnChecked(T p_element)
    {
        return new InnerHashSet<>(this);    }

    @Override
    public InnerSet<T> removeElement(Object p_element)
    {
                if(element_1.equals(p_element))
            return  new InnerSet_19<>(element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_2.equals(p_element))
            return  new InnerSet_19<>(element_1, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_3.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_4.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_5.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_6.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_7.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_8.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_9.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_10.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_11.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_12.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_13.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_14.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_15.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_16.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_17, element_18, element_19, element_20);
         else                 if(element_17.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_18, element_19, element_20);
         else                 if(element_18.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_19, element_20);
         else                 if(element_19.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_20);
         else                 if(element_20.equals(p_element))
            return  new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19);
                        else
            return this;
    }

    @Override
    public boolean containsElement(Object p_element)
    {
        return element_1.equals(p_element) || element_2.equals(p_element) || element_3.equals(p_element) || element_4.equals(p_element) || element_5.equals(p_element) || element_6.equals(p_element) || element_7.equals(p_element) || element_8.equals(p_element) || element_9.equals(p_element) || element_10.equals(p_element) || element_11.equals(p_element) || element_12.equals(p_element) || element_13.equals(p_element) || element_14.equals(p_element) || element_15.equals(p_element) || element_16.equals(p_element) || element_17.equals(p_element) || element_18.equals(p_element) || element_19.equals(p_element) || element_20.equals(p_element);
    }


    public T getElement(int index)
    {switch(index) {
                case 1:
            return element_1;
                case 2:
            return element_2;
                case 3:
            return element_3;
                case 4:
            return element_4;
                case 5:
            return element_5;
                case 6:
            return element_6;
                case 7:
            return element_7;
                case 8:
            return element_8;
                case 9:
            return element_9;
                case 10:
            return element_10;
                case 11:
            return element_11;
                case 12:
            return element_12;
                case 13:
            return element_13;
                case 14:
            return element_14;
                case 15:
            return element_15;
                case 16:
            return element_16;
                case 17:
            return element_17;
                case 18:
            return element_18;
                case 19:
            return element_19;
                case 20:
            return element_20;
                default:
            return null;
            }
    }


    public InnerSet<T> addAllElements(InnerSet<T> innerSet) {
        return innerSet.addElement(element_1).addElement(element_2).addElement(element_3).addElement(element_4).addElement(element_5).addElement(element_6).addElement(element_7).addElement(element_8).addElement(element_9).addElement(element_10).addElement(element_11).addElement(element_12).addElement(element_13).addElement(element_14).addElement(element_15).addElement(element_16).addElement(element_17).addElement(element_18).addElement(element_19).addElement(element_20);
    }


    @Override
    public InnerSet<T> removeAllElements(InnerSet<T> innerSet) {
        return innerSet.removeElement(element_1).removeElement(element_2).removeElement(element_3).removeElement(element_4).removeElement(element_5).removeElement(element_6).removeElement(element_7).removeElement(element_8).removeElement(element_9).removeElement(element_10).removeElement(element_11).removeElement(element_12).removeElement(element_13).removeElement(element_14).removeElement(element_15).removeElement(element_16).removeElement(element_17).removeElement(element_18).removeElement(element_19).removeElement(element_20);
    }

    @Override
    public InnerSet<T> retainAllElements(InnerSet<T> innerSet) {
        InnerSet<T> i = this;
                if (!innerSet.containsElement(element_1)) i = i.removeElement(element_1);
                if (!innerSet.containsElement(element_2)) i = i.removeElement(element_2);
                if (!innerSet.containsElement(element_3)) i = i.removeElement(element_3);
                if (!innerSet.containsElement(element_4)) i = i.removeElement(element_4);
                if (!innerSet.containsElement(element_5)) i = i.removeElement(element_5);
                if (!innerSet.containsElement(element_6)) i = i.removeElement(element_6);
                if (!innerSet.containsElement(element_7)) i = i.removeElement(element_7);
                if (!innerSet.containsElement(element_8)) i = i.removeElement(element_8);
                if (!innerSet.containsElement(element_9)) i = i.removeElement(element_9);
                if (!innerSet.containsElement(element_10)) i = i.removeElement(element_10);
                if (!innerSet.containsElement(element_11)) i = i.removeElement(element_11);
                if (!innerSet.containsElement(element_12)) i = i.removeElement(element_12);
                if (!innerSet.containsElement(element_13)) i = i.removeElement(element_13);
                if (!innerSet.containsElement(element_14)) i = i.removeElement(element_14);
                if (!innerSet.containsElement(element_15)) i = i.removeElement(element_15);
                if (!innerSet.containsElement(element_16)) i = i.removeElement(element_16);
                if (!innerSet.containsElement(element_17)) i = i.removeElement(element_17);
                if (!innerSet.containsElement(element_18)) i = i.removeElement(element_18);
                if (!innerSet.containsElement(element_19)) i = i.removeElement(element_19);
                if (!innerSet.containsElement(element_20)) i = i.removeElement(element_20);
                return i;
    }

    @Override
    public boolean containsAllElements(InnerSet<T> innerSet) {
        return  innerSet.containsElement(element_1) && innerSet.containsElement(element_2) && innerSet.containsElement(element_3) && innerSet.containsElement(element_4) && innerSet.containsElement(element_5) && innerSet.containsElement(element_6) && innerSet.containsElement(element_7) && innerSet.containsElement(element_8) && innerSet.containsElement(element_9) && innerSet.containsElement(element_10) && innerSet.containsElement(element_11) && innerSet.containsElement(element_12) && innerSet.containsElement(element_13) && innerSet.containsElement(element_14) && innerSet.containsElement(element_15) && innerSet.containsElement(element_16) && innerSet.containsElement(element_17) && innerSet.containsElement(element_18) && innerSet.containsElement(element_19) && innerSet.containsElement(element_20);
    }

    @Override
    public String toString()
    {
        return "{" + element_1 + ", " + element_2 + ", " + element_3 + ", " + element_4 + ", " + element_5 + ", " + element_6 + ", " + element_7 + ", " + element_8 + ", " + element_9 + ", " + element_10 + ", " + element_11 + ", " + element_12 + ", " + element_13 + ", " + element_14 + ", " + element_15 + ", " + element_16 + ", " + element_17 + ", " + element_18 + ", " + element_19 + ", " + element_20 + " }";
    }
    
    @Override
    public int getSize()
    {
        return 20;
    }

    @Override
    public Iterator<T> iterator() {
        return new InnerSetIterator<>(this);
    }

    @Override
    public InnerSet<T> clear(boolean unused) {
        return (InnerSet<T>) InnerSet_0.singleton;
    }
}
