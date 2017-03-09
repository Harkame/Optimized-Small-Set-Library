package j.implementation.microSet;

import java.util.Collection;
import java.util.Iterator;

public class InnerSet_5 <T> extends AbstractInnerSet<T>
{
        protected T element_1;
        protected T element_2;
        protected T element_3;
        protected T element_4;
        protected T element_5;
        
    public InnerSet_5(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5)
    {
                element_1 = p_element_1;
                element_2 = p_element_2;
                element_3 = p_element_3;
                element_4 = p_element_4;
                element_5 = p_element_5;
            }

    public InnerSet_5(InnerSet_4<T> i, T el)
    {
            element_1 = i.element_1;            element_2 = i.element_2;            element_3 = i.element_3;            element_4 = i.element_4;                    element_5 = el;
    }
    
    @Override
    public InnerSet<T> addElement(T p_element)
    {
        if(element_1.equals(p_element) || element_2.equals(p_element) || element_3.equals(p_element) || element_4.equals(p_element) || element_5.equals(p_element))
            return this;
        else
            return new InnerHashSet<>(this);    }

    @Override
    public InnerSet<T> removeElement(Object p_element)
    {
                if(element_1.equals(p_element))
            return new InnerSet_4<>(element_2, element_3, element_4, element_5);
         else                 if(element_2.equals(p_element))
            return new InnerSet_4<>(element_1, element_3, element_4, element_5);
         else                 if(element_3.equals(p_element))
            return new InnerSet_4<>(element_1, element_2, element_4, element_5);
         else                 if(element_4.equals(p_element))
            return new InnerSet_4<>(element_1, element_2, element_3, element_5);
         else                 if(element_5.equals(p_element))
            return new InnerSet_4<>(element_1, element_2, element_3, element_4);
                        else
            return this;
    }

    @Override
    public boolean containsElement(Object p_element)
    {
        return element_1.equals(p_element) || element_2.equals(p_element) || element_3.equals(p_element) || element_4.equals(p_element) || element_5.equals(p_element);
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
                default:
            return null;
            }
    }


    public InnerSet<T> addAllElements(InnerSet<T> innerSet) {
                    innerSet = innerSet.addElement(element_1);
                    innerSet = innerSet.addElement(element_2);
                    innerSet = innerSet.addElement(element_3);
                    innerSet = innerSet.addElement(element_4);
                    innerSet = innerSet.addElement(element_5);
                return innerSet;
    }


    @Override
    public InnerSet<T> removeAllElements(InnerSet<T> innerSet) {
        return null;
    }

    @Override
    public InnerSet<T> retainAllElements(InnerSet<T> innerSet) {
        InnerSet<T> i = this;
                if (!innerSet.containsElement(element_1)) i = i.removeElement(element_1);
                if (!innerSet.containsElement(element_2)) i = i.removeElement(element_2);
                if (!innerSet.containsElement(element_3)) i = i.removeElement(element_3);
                if (!innerSet.containsElement(element_4)) i = i.removeElement(element_4);
                if (!innerSet.containsElement(element_5)) i = i.removeElement(element_5);
                return i;
    }

    @Override
    public boolean containsAllElements(InnerSet<T> innerSet) {
        return  innerSet.containsElement(element_1) && innerSet.containsElement(element_2) && innerSet.containsElement(element_3) && innerSet.containsElement(element_4) && innerSet.containsElement(element_5);
    }

    @Override
    public String toString()
    {
        return "{" + element_1 + ", " + element_2 + ", " + element_3 + ", " + element_4 + ", " + element_5 + " }";
    }
    
    @Override
    public int getSize()
    {
        return 5;
    }

    @Override
    public Iterator<T> getIterator() {
        return new InnerSetIterator<>(this);
    }

}
