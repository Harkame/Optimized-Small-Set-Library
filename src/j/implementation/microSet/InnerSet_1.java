package j.implementation.microSet;

import java.util.Iterator;

public class InnerSet_1 <T> extends AbstractInnerSet<T>
{
        protected T element_1;
        
    public InnerSet_1(T p_element_1)
    {
                element_1 = p_element_1;
            }

    public InnerSet_1(InnerSet_1<T> i)
    {
            element_1 = i.element_1;
        }

    public InnerSet_1<T> copy() {
        return new InnerSet_1(this);
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
    public InnerSet<T> addUnChecked(T p_element)
    {
        return new InnerSet_2<>(this, p_element);    }

    @Override
    public InnerSet<T> removeElement(Object p_element)
    {
                if(element_1.equals(p_element))
            return  (InnerSet_0<T>) InnerSet_0.singleton
            ;
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


    public InnerSet<T> addAllElements(InnerSet<T> innerSet) {
                    innerSet = innerSet.addElement(element_1);
                return innerSet;
    }


    @Override
    public InnerSet<T> removeAllElements(InnerSet<T> innerSet) {
                   innerSet = innerSet.removeElement(element_1);
                  return innerSet;
    }

    @Override
    public InnerSet<T> retainAllElements(InnerSet<T> innerSet) {
        InnerSet<T> i = this;
                if (!innerSet.containsElement(element_1)) i = i.removeElement(element_1);
                return i;
    }

    @Override
    public boolean containsAllElements(InnerSet<T> innerSet) {
        return  innerSet.containsElement(element_1);
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
    public Iterator<T> iterator() {
        return new InnerSetIterator<>(this);
    }

}
