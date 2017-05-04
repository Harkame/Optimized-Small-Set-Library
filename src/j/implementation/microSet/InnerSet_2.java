package j.implementation.microSet;

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

    public InnerSet_2(InnerSet_2<T> i)
    {
            element_1 = i.element_1;
            element_2 = i.element_2;
        }

    public InnerSet_2<T> copy() {
        return this;
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
    public InnerSet<T> addUnChecked(T p_element)
    {
        return new InnerSet_3<>(this, p_element);    }

    @Override
    public InnerSet<T> removeElement(Object p_element)
    {
                if(element_1.equals(p_element))
            return  new InnerSet_1<>(element_2);
         else                 if(element_2.equals(p_element))
            return  new InnerSet_1<>(element_1);
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
                case 0:
            return element_1;
                case 1:
            return element_2;
                default:
            return null;
            }
    }


    public InnerSet<T> addAllElements(InnerSet<T> innerSet) {
        // Reverse the add if the innerSet we add is smaller than this
        if (innerSet.getSize() < this.getSize()) {
            return innerSet.addAllElements(this);
        }
        return innerSet.addElement(element_1).addElement(element_2);
    }


    @Override
    public InnerSet<T> removeAllElements(InnerSet<T> innerSet) {
        return innerSet.removeElement(element_1).removeElement(element_2);
    }

    @Override
    public InnerSet<T> retainAllElements(InnerSet<T> innerSet) {
        InnerSet<T> i = this;
                if (!innerSet.containsElement(element_1)) i = i.removeElement(element_1);
                if (!innerSet.containsElement(element_2)) i = i.removeElement(element_2);
                return i;
    }

    @Override
    public boolean containsAllElements(InnerSet<T> innerSet) {
        return  innerSet.containsElement(element_1) && innerSet.containsElement(element_2);
    }

    public InnerSet<T> addAllAndPropagate(InnerSet<T> innerSet, MicroSet<T> microSetToPropagate) {
        return innerSet.addAllAndPropagateReverse(this, microSetToPropagate);
    }


    public InnerSet<T> addAllAndPropagateReverse(InnerSet<T> innerSet, MicroSet<T> microSetToPropagate) {
        return innerSet.addAndPropagate(element_1, microSetToPropagate).addAndPropagate(element_2, microSetToPropagate);
    }

    public InnerSet<T> addAndPropagate(T p_element, MicroSet<T> microSetToPropagate) {
        if(element_1.equals(p_element) || element_2.equals(p_element))
            return this;
        else {
            microSetToPropagate.add(p_element);
            return new InnerSet_3<>(this, p_element);        }
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
    public Iterator<T> iterator() {
        return new InnerSetIterator<>(this);
    }

    @Override
    public InnerSet<T> clear(boolean unused) {
        return (InnerSet<T>) InnerSet_0.singleton;
    }
}
