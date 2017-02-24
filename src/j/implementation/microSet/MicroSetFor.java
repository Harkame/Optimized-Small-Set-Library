package j.implementation.microSet;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.Set;

/**
 * Created by fly on 2/23/17.
 */
public class MicroSetFor<T> implements Set<T> {

    ArrayList<T> datas;

    public MicroSetFor() {
        datas = new ArrayList<>();
    }

    @Override
    public int size() {
        return datas.size();
    }

    @Override
    public boolean isEmpty() {
        return datas.isEmpty();
    }

    @Override
    public boolean contains(Object o) {
        return datas.contains(o);
    }

    @Override
    public Iterator<T> iterator() {
        return null;
    }

    @Override
    public Object[] toArray() {
        return new Object[0];
    }

    @Override
    public <T1> T1[] toArray(T1[] t1s) {
        return null;
    }

    @Override
    public boolean add(T t) {
        boolean res = false;
        if (!this.contains(t)) {
            datas.add(t);
            res = true;
        }
        return res;
    }

    @Override
    public boolean remove(Object o) {
        return datas.remove(o);
    }

    @Override
    public boolean containsAll(Collection<?> collection) {
        return false;
    }

    @Override
    public boolean addAll(Collection<? extends T> collection) {
        return false;
    }

    @Override
    public boolean retainAll(Collection<?> collection) {
        return false;
    }

    @Override
    public boolean removeAll(Collection<?> collection) {
        return false;
    }

    @Override
    public void clear() {

    }
}
