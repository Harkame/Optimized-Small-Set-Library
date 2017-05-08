package j.implementation.microSet;

import java.util.HashSet;
import java.util.Iterator;

public class InnerHashSet<T> extends HashSet<T> implements InnerSet<T>
{

	public InnerHashSet() {
        super();
    }

    public InnerHashSet(InnerSet i) {
        this();
        for (InnerSetIterator<T> iterator = new InnerSetIterator<>(i); iterator.hasNext(); ) {
            add(iterator.next());
        }
    }

    public InnerHashSet(InnerSet<T> i, T p_element) {
        this();
        for (InnerSetIterator<T> iterator = new InnerSetIterator<>(i); iterator.hasNext(); ) {
            add(iterator.next());
        }
        add(p_element);
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

    @Override
    public InnerSet<T> copy() {
        return new InnerHashSet<>(this);
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
    public InnerSet<T> addAndPropagate(T p_element, MicroSet<T> microSetToPropagate) {
        if (!contains(p_element)) {
            microSetToPropagate.add(p_element);
            add(p_element);
        }
        return this;
    }

    public InnerSet<T> addAllAndPropagate(InnerSet<T> innerSet, MicroSet<T> microSetToPropagate) {
        return innerSet.addAllAndPropagateReverse(this, microSetToPropagate);
    }

    @Override
    public InnerSet<T> addAllAndPropagateReverse(InnerSet<T> innerSet, MicroSet<T> microSetPropagate) {
        for (T el : this) {
            innerSet = innerSet.addAndPropagate(el, microSetPropagate);
        }
        return innerSet;
    }

    @Override
    public int getSize() {
        return size();
    }

    @Override
    public InnerSet<T> clear(boolean unused) {
        this.clear();
        return this;
    }
}
