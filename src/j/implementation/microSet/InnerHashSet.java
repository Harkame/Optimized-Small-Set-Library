package j.implementation.microSet;

import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;


public class InnerHashSet<T> implements InnerSet<T> {

    HashSet<T> datas;

    public InnerHashSet() {
        this.datas = new HashSet<>();
    }

    public InnerHashSet(InnerSet i) {
        super();
        Iterator it = i.getIterator();
        while(it.hasNext()) {
            this.datas.add((T) it.next());
        }
    }

    @Override
    public InnerSet<T> addElement(T p_element) {
        datas.add(p_element);
        return this;
    }

    @Override
    public InnerSet<T> addAllElements(Collection<? extends T> p_newC) {
        datas.addAll(p_newC);
        return this;
    }

    @Override
    public boolean containsElement(Object p_element) {
        return datas.contains(p_element);
    }

    @Override
    public boolean containsAllElements(Collection<?> p_c) {
        return datas.containsAll(p_c);
    }

    @Override
    public T getElement(int index) {
        return null;
    }

    public Iterator<T> getIterator() {
        return datas.iterator();
    }

    @Override
    public InnerSet<T> removeElement(Object p_element) {
        datas.remove(p_element);
        return this;
    }

    @Override
    public InnerSet<T> removeAllElements(Collection<?> p_cToDelete) {
        datas.removeAll(p_cToDelete);
        return null;
    }

    @Override
    public InnerSet<T> retainAllElements(Collection<?> p_cToKeep) {
        datas.retainAll(p_cToKeep);
        return this;
    }

    @Override
    public int getSize() {
        return 0;
    }
}
