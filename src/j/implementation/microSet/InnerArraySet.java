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

    public InnerArraySet() {
        super(Generator.TO_GENERATE);
    }

    @Override
    public InnerSet<T> addElement(T p_element) {
        if (!contains(p_element)) {
            add(p_element);
        }
        return this;
    }

    @Override
    public InnerSet<T> addUnChecked(T p_element) {
        add(p_element);
        return this;
    }

    @Override
    public InnerSet<T> addAllElements(InnerSet<T> innerSet) {
        Iterator<T> it = innerSet.iterator();
        while (it.hasNext()) {
            addElement(it.next());
        }
        return this;
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
        remove(p_element);
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
    public int getSize() {
        return size();
    }

    @Override
    public Iterator<T> iterator() {
        return iterator();
    }

    @Override
    public InnerSet<T> copy() {
        return copy();
    }
}
