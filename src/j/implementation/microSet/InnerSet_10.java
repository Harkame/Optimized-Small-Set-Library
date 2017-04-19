package j.implementation.microSet;

import java.util.Iterator;

public class InnerSet_10 <T> extends AbstractInnerSet<T>
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
        
    public InnerSet_10(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5, T p_element_6, T p_element_7, T p_element_8, T p_element_9, T p_element_10)
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
            }

    public InnerSet_10(InnerSet_10<T> i)
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
        }

    public InnerSet_10<T> copy() {
        return new InnerSet_10(this);
    }

    public InnerSet_10(InnerSet_9<T> i, T el)
    {
            element_1 = i.element_1;            element_2 = i.element_2;            element_3 = i.element_3;            element_4 = i.element_4;            element_5 = i.element_5;            element_6 = i.element_6;            element_7 = i.element_7;            element_8 = i.element_8;            element_9 = i.element_9;                    element_10 = el;
    }
    
    @Override
    public InnerSet<T> addElement(T p_element)
    {
        if(element_1.equals(p_element) || element_2.equals(p_element) || element_3.equals(p_element) || element_4.equals(p_element) || element_5.equals(p_element) || element_6.equals(p_element) || element_7.equals(p_element) || element_8.equals(p_element) || element_9.equals(p_element) || element_10.equals(p_element))
            return this;
        else
            return new InnerArraySet<T>(this, p_element);    }

    @Override
    public InnerSet<T> addUnChecked(T p_element)
    {
        return new InnerArraySet<T>(this, p_element);    }

    @Override
    public InnerSet<T> removeElement(Object p_element)
    {
                if(element_1.equals(p_element))
            return  new InnerSet_9<>(element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10);
         else                 if(element_2.equals(p_element))
            return  new InnerSet_9<>(element_1, element_3, element_4, element_5, element_6, element_7, element_8, element_9, element_10);
         else                 if(element_3.equals(p_element))
            return  new InnerSet_9<>(element_1, element_2, element_4, element_5, element_6, element_7, element_8, element_9, element_10);
         else                 if(element_4.equals(p_element))
            return  new InnerSet_9<>(element_1, element_2, element_3, element_5, element_6, element_7, element_8, element_9, element_10);
         else                 if(element_5.equals(p_element))
            return  new InnerSet_9<>(element_1, element_2, element_3, element_4, element_6, element_7, element_8, element_9, element_10);
         else                 if(element_6.equals(p_element))
            return  new InnerSet_9<>(element_1, element_2, element_3, element_4, element_5, element_7, element_8, element_9, element_10);
         else                 if(element_7.equals(p_element))
            return  new InnerSet_9<>(element_1, element_2, element_3, element_4, element_5, element_6, element_8, element_9, element_10);
         else                 if(element_8.equals(p_element))
            return  new InnerSet_9<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_9, element_10);
         else                 if(element_9.equals(p_element))
            return  new InnerSet_9<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_10);
         else                 if(element_10.equals(p_element))
            return  new InnerSet_9<>(element_1, element_2, element_3, element_4, element_5, element_6, element_7, element_8, element_9);
                        else
            return this;
    }

    @Override
    public boolean containsElement(Object p_element)
    {
        return element_1.equals(p_element) || element_2.equals(p_element) || element_3.equals(p_element) || element_4.equals(p_element) || element_5.equals(p_element) || element_6.equals(p_element) || element_7.equals(p_element) || element_8.equals(p_element) || element_9.equals(p_element) || element_10.equals(p_element);
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
                default:
            return null;
            }
    }


    public InnerSet<T> addAllElements(InnerSet<T> innerSet) {
        return innerSet.addElement(element_1).addElement(element_2).addElement(element_3).addElement(element_4).addElement(element_5).addElement(element_6).addElement(element_7).addElement(element_8).addElement(element_9).addElement(element_10);
    }


    @Override
    public InnerSet<T> removeAllElements(InnerSet<T> innerSet) {
        return innerSet.removeElement(element_1).removeElement(element_2).removeElement(element_3).removeElement(element_4).removeElement(element_5).removeElement(element_6).removeElement(element_7).removeElement(element_8).removeElement(element_9).removeElement(element_10);
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
                return i;
    }

    @Override
    public boolean containsAllElements(InnerSet<T> innerSet) {
        return  innerSet.containsElement(element_1) && innerSet.containsElement(element_2) && innerSet.containsElement(element_3) && innerSet.containsElement(element_4) && innerSet.containsElement(element_5) && innerSet.containsElement(element_6) && innerSet.containsElement(element_7) && innerSet.containsElement(element_8) && innerSet.containsElement(element_9) && innerSet.containsElement(element_10);
    }

    public InnerSet<T> addAllAndPropagate(InnerSet<T> innerSet, MicroSet<T> microSet) {
        return innerSet.addAndPropagate(element_1, microSet).addAndPropagate(element_2, microSet).addAndPropagate(element_3, microSet).addAndPropagate(element_4, microSet).addAndPropagate(element_5, microSet).addAndPropagate(element_6, microSet).addAndPropagate(element_7, microSet).addAndPropagate(element_8, microSet).addAndPropagate(element_9, microSet).addAndPropagate(element_10, microSet);
    }

    public InnerSet<T> addAndPropagate(T p_element, MicroSet<T> microSet) {
        if(element_1.equals(p_element) || element_2.equals(p_element) || element_3.equals(p_element) || element_4.equals(p_element) || element_5.equals(p_element) || element_6.equals(p_element) || element_7.equals(p_element) || element_8.equals(p_element) || element_9.equals(p_element) || element_10.equals(p_element))
            return this;
        else {
            microSet.add(p_element);
            return new InnerArraySet<T>(this, p_element);        }
    }

    @Override
    public String toString()
    {
        return "{" + element_1 + ", " + element_2 + ", " + element_3 + ", " + element_4 + ", " + element_5 + ", " + element_6 + ", " + element_7 + ", " + element_8 + ", " + element_9 + ", " + element_10 + " }";
    }
    
    @Override
    public int getSize()
    {
        return 10;
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
