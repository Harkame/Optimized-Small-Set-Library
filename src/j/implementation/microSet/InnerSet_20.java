package j.implementation.microSet;

import java.util.Collection;
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
    public InnerSet<T> removeElement(Object p_element)
    {
                if(element_1.equals(p_element))
            return new InnerSet_19<>(element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_2.equals(p_element))
            return new InnerSet_19<>(element_1, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_3.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_4.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_5.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_6.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_7.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_8.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_9.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_10.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_11.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_12.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_13, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_13.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_14, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_14.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_15, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_15.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_16, element_17, element_18, element_19, element_20);
         else                 if(element_16.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_17, element_18, element_19, element_20);
         else                 if(element_17.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_18, element_19, element_20);
         else                 if(element_18.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_19, element_20);
         else                 if(element_19.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_20);
         else                 if(element_20.equals(p_element))
            return new InnerSet_19<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10, element_11, element_12, element_13, element_14, element_15, element_16, element_17, element_18, element_19);
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

    @Override
    public InnerSet<T> addAllElements(InnerSet<T> innerSet) {
        return null;
    }

    public InnerSet<T> addAllReverse(InnerSet<T> innerSet) {
                    innerSet = innerSet.addElement(element_1);
                    innerSet = innerSet.addElement(element_2);
                    innerSet = innerSet.addElement(element_3);
                    innerSet = innerSet.addElement(element_4);
                    innerSet = innerSet.addElement(element_5);
                    innerSet = innerSet.addElement(element_6);
                    innerSet = innerSet.addElement(element_7);
                    innerSet = innerSet.addElement(element_8);
                    innerSet = innerSet.addElement(element_9);
                    innerSet = innerSet.addElement(element_10);
                    innerSet = innerSet.addElement(element_11);
                    innerSet = innerSet.addElement(element_12);
                    innerSet = innerSet.addElement(element_13);
                    innerSet = innerSet.addElement(element_14);
                    innerSet = innerSet.addElement(element_15);
                    innerSet = innerSet.addElement(element_16);
                    innerSet = innerSet.addElement(element_17);
                    innerSet = innerSet.addElement(element_18);
                    innerSet = innerSet.addElement(element_19);
                    innerSet = innerSet.addElement(element_20);
                return innerSet;
    }


    @Override
    public InnerSet<T> removeAllElements(InnerSet<T> innerSet) {
        return null;
    }

    @Override
    public InnerSet<T> retainAllElements(InnerSet<T> innerSet) {
        return null;
    }

    @Override
    public boolean containsAllElements(InnerSet<T> innerSet) {
        return false;
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
    public Iterator<T> getIterator() {
        return new InnerSetIterator<>(this);
    }

}
