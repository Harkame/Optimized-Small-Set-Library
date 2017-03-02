package j.implementation.microSet;

import java.util.Collection;
import java.util.Iterator;

public class InnerSet_1 <T> implements InnerSet<T>
{
        protected T element_1;
        
    public InnerSet_1(T p_element_1)
    {
                element_1 = p_element_1;
            }

    public InnerSet_1(InnerSet_0<T> i, T el)
    {
                    element_1 = el;
    }
    
    @Override
    public InnerSet<T> addElement(T p_element)
    {
        if(element_1.equals(p_element))
            return this;
        else
            return new InnerSet_2<>(this, p_element);    }

    @Override
    public InnerSet<T> removeElement(Object p_element)
    {
                if(element_1.equals(p_element))
            return new InnerSet_0<>();
                        else
            return this;
    }

    @Override
    public boolean containsElement(Object p_element)
    {
        return element_1.equals(p_element);
    }


    public T getElement(int index)
    {switch(index) {
                case 1:
            return element_1;
                default:
            return null;
            }
    }

    @Override
    public InnerSet<T> addAllElements(Collection<? extends T> p_newC) {
        return null;
    }

    @Override
    public InnerSet<T> removeAllElements(Collection<?> p_cToDelete) {
        return null;
    }

    @Override
    public InnerSet<T> retainAllElements(Collection<?> p_cToKeep) {
        return null;
    }

    @Override
    public boolean containsAllElements(Collection<?> p_c) {
        return false;
    }

    @Override
    public String toString()
    {
        return "{" + element_1 + " }";
    }
    
    @Override
    public int getSize()
    {
        return 1;
    }

    @Override
    public Iterator<T> getIterator() {
        return new InnerSetIterator<>(this);
    }

}
