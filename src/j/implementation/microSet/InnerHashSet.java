package j.implementation.microSet;

import java.util.HashSet;
import java.util.Iterator;

public class InnerHashSet<T> extends HashSet<T> implements InnerSet<T>
{

	public InnerHashSet() {
        super();
    }

    public InnerHashSet(InnerSet<T> i) {
        super(); // DANS INNERSET_15
        for (T el : this) {
            add(el);
        }
    }

    @Override
    public InnerSet<T> addElement(T p_element) {
        add(p_element);
        return this;
    }

    @Override
    public InnerSet<T> addUnChecked(T p_element) {
        return addElement(p_element);
    }

    @Override
    public InnerSet<T> addAllElements(InnerSet<T> innerSet) {
        for (T el : this) {
            innerSet = innerSet.addElement(el);
        }
        return innerSet;
    }

    @Override
    public boolean containsElement(Object p_element) {
        return contains(p_element);
    }

    @Override
    public boolean containsAllElements(InnerSet<T> innerSet) {
        //return containsAll(innerSet);
        return false;
    }

    @Override
    public T getElement(int index) {
        return null;
    }

    public Iterator<T> iterator() {
        return iterator();
    }

    @Override
    public InnerSet<T> copy() {
        return null;
    }

    @Override
    public InnerSet<T> removeElement(Object p_element) {
        remove(p_element);
        return this;
    }

    @Override
    public InnerSet<T> removeAllElements(InnerSet<T> innerSet) {
        //removeAll(innerSet);
        return null;
    }

    @Override
    public InnerSet<T> retainAllElements(InnerSet<T> innerSet) {
       // retainAll(innerSet);
        return this;
    }

    @Override
    public int getSize() {
        return 0;
    }
}
