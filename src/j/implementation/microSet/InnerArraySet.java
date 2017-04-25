package j.implementation.microSet;

import j.generator.Generator;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.Set;

/**
 * Created by fly on 2/23/17.
 */
public class InnerArraySet<T> extends ArrayList<T> implements InnerSet<T> {

    private static final int MAX_SIZE = 20;

    public InnerArraySet() {
        super(MAX_SIZE); // Optimise the array length to the size of InnerSet
    }

    public InnerArraySet(InnerSet<T> i) {
        this();
        for (InnerSetIterator<T> iterator = new InnerSetIterator<>(i); iterator.hasNext(); ) {
            add(iterator.next());
        }
    }

    public InnerArraySet(InnerSet<T> i, T p_element) {
        this(i);
        add(p_element);
    }

    @Override
    public InnerSet<T> addElement(T p_element) {
        if (!contains(p_element)) {
            if (getSize() >= MAX_SIZE) {
                return new InnerHashSet<T>(this, p_element);
            } else {
                add(p_element);
            }
        }
        return this;
    }

    @Override
    public InnerSet<T> addUnChecked(T p_element) {
        if (getSize() >= MAX_SIZE) {
            return new InnerHashSet<T>(this, p_element);
        } else {
            add(p_element);
            return this;
        }
    }

    @Override
    public InnerSet<T> addAllElements(InnerSet<T> innerSet) {
        // Reverse the add if the innerSet we add is smaller than this
        if (innerSet.getSize() < this.getSize()) {
            return innerSet.addAllElements(this);
        }
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
        return false;
    }

    @Override
    public T getElement(int index) {
        return get(index);
    }

    @Override
    public InnerSet<T> removeElement(Object p_element) {
        for (int index = 0; index < size(); index++) {
            if (p_element.equals(get(index))) {
                set(index, get(size() - 1));
                remove(size() - 1);
            }
        }
        return this;
    }

    @Override
    public InnerSet<T> removeAllElements(InnerSet<T> innerSet) {
        Iterator<T> it = innerSet.iterator();
        while (it.hasNext()) {
            removeElement(it.next());
        }
        return this;
    }

    @Override
    public InnerSet<T> retainAllElements(InnerSet<T> innerSet) {
        return null;
    }

    @Override
    public InnerSet<T> addAndPropagate(T p_element, MicroSet<T> microSetToPropagate) {
        if (!contains(p_element)) {
            microSetToPropagate.add(p_element);
            if (getSize() == MAX_SIZE) {
                return new InnerHashSet<>(this, p_element);
            } else {
                add(p_element);
            }
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
    public InnerSet<T> copy() {
        return new InnerArraySet<>(this);
    }

    @Override
    public InnerSet<T> clear(boolean unused) {
        this.clear();
        return this;
    }
}
