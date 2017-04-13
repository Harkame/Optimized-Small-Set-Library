package j.implementation.microSet;

import java.util.Iterator;

public class InnerSet_3 <T> extends AbstractInnerSet<T>
{
        protected T element_1;
        protected T element_2;
        protected T element_3;
        
    public InnerSet_3(T p_element_1, T p_element_2, T p_element_3)
    {
                element_1 = p_element_1;
                element_2 = p_element_2;
                element_3 = p_element_3;
            }

    public InnerSet_3(InnerSet_3<T> i)
    {
            element_1 = i.element_1;
            element_2 = i.element_2;
            element_3 = i.element_3;
        }

    public InnerSet_3<T> copy() {
        return new InnerSet_3(this);
    }

    public InnerSet_3(InnerSet_2<T> i, T el)
    {
            element_1 = i.element_1;            element_2 = i.element_2;                    element_3 = el;
    }
    
    @Override
    public InnerSet<T> addElement(T p_element)
    {
        if(element_1.equals(p_element) || element_2.equals(p_element) || element_3.equals(p_element))
            return this;
        else
            return new InnerSet_4<>(this, p_element);    }

    @Override
    public InnerSet<T> addUnChecked(T p_element)
    {
        return new InnerSet_4<>(this, p_element);    }

    @Override
    public InnerSet<T> removeElement(Object p_element)
    {
                if(element_1.equals(p_element))
            return  new InnerSet_2<>(element_2, element_3);
         else                 if(element_2.equals(p_element))
            return  new InnerSet_2<>(element_1, element_3);
         else                 if(element_3.equals(p_element))
            return  new InnerSet_2<>(element_1, element_2);
                        else
            return this;
    }

    @Override
    public boolean containsElement(Object p_element)
    {
        return element_1.equals(p_element) || element_2.equals(p_element) || element_3.equals(p_element);
    }


    public T getElement(int index)
    {switch(index) {
                case 1:
            return element_1;
                case 2:
            return element_2;
                case 3:
            return element_3;
                default:
            return null;
            }
    }


    public InnerSet<T> addAllElements(InnerSet<T> innerSet) {
        return innerSet.addElement(element_1).addElement(element_2).addElement(element_3);
    }


    @Override
    public InnerSet<T> removeAllElements(InnerSet<T> innerSet) {
                   innerSet = innerSet.removeElement(element_1);
                      innerSet = innerSet.removeElement(element_2);
                      innerSet = innerSet.removeElement(element_3);
                  return innerSet;
    }

    @Override
    public InnerSet<T> retainAllElements(InnerSet<T> innerSet) {
        InnerSet<T> i = this;
                if (!innerSet.containsElement(element_1)) i = i.removeElement(element_1);
                if (!innerSet.containsElement(element_2)) i = i.removeElement(element_2);
                if (!innerSet.containsElement(element_3)) i = i.removeElement(element_3);
                return i;
    }

    @Override
    public boolean containsAllElements(InnerSet<T> innerSet) {
        return  innerSet.containsElement(element_1) && innerSet.containsElement(element_2) && innerSet.containsElement(element_3);
    }

    @Override
    public String toString()
    {
        return "{" + element_1 + ", " + element_2 + ", " + element_3 + " }";
    }
    
    @Override
    public int getSize()
    {
        return 3;
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
