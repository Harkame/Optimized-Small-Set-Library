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
        super(Generator.TO_GENERATE); // Optimise the array length to the size of InnerSet
    }

    public InnerArraySet(InnerSet i) {
        this();
        for (Iterator<T> it = i.iterator(); it.hasNext(); ) {
            add(it.next());
        }
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

/*    private void fastRemove(T p_element) {
        modCount++;
        for (int index = 0; index < size(); index++)
            if (p_element.equals(super.elementData[index])) {
                fastRemove(index);
                return true;
            }
    }*/

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
    public InnerSet<T> copy() {
        return new InnerArraySet<>(this);
    }

    @Override
    public InnerSet<T> clear(boolean unused) {
        this.clear();
        return this;
    }
}
