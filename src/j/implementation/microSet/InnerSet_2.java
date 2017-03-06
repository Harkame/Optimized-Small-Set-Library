package j.implementation.microSet;

import java.util.Collection;
import java.util.Iterator;

public class InnerSet_2 <T> extends AbstractInnerSet<T>
{
        protected T element_1;
        protected T element_2;
        
    public InnerSet_2(T p_element_1, T p_element_2)
    {
                element_1 = p_element_1;
                element_2 = p_element_2;
            }

    public InnerSet_2(InnerSet_1<T> i, T el)
    {
            element_1 = i.element_1;                    element_2 = el;
    }
    
    @Override
    public InnerSet<T> addElement(T p_element)
    {
        if(element_1.equals(p_element) || element_2.equals(p_element))
            return this;
        else
            return new InnerSet_3<>(this, p_element);    }

    @Override
    public InnerSet<T> removeElement(Object p_element)
    {
                if(element_1.equals(p_element))
            return new InnerSet_1<>(element_2);
         else                 if(element_2.equals(p_element))
            return new InnerSet_1<>(element_1);
                        else
            return this;
    }

    @Override
    public boolean containsElement(Object p_element)
    {
        return element_1.equals(p_element) || element_2.equals(p_element);
    }


    public T getElement(int index)
    {switch(index) {
                case 1:
            return element_1;
                case 2:
            return element_2;
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
        return "{" + element_1 + ", " + element_2 + " }";
    }
    
    @Override
    public int getSize()
    {
        return 2;
    }

    @Override
    public Iterator<T> getIterator() {
        return new InnerSetIterator<>(this);
    }

}
