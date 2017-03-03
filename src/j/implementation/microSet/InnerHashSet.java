package j.implementation.microSet;

import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;

public class InnerHashSet<T> extends HashSet<T> implements InnerSet<T>
{
	private static final long serialVersionUID = 1L;

	public InnerHashSet() {
        super();
    }

    public InnerHashSet(InnerSet<T> i) {
        super(); // DANS INNERSET_15
        Iterator<T> it = i.getIterator();
        while(it.hasNext()) {
            add((T) it.next());
        }
    }

    @Override
    public InnerSet<T> addElement(T p_element) {
        add(p_element);
        return this;
    }

    @Override
    public InnerSet<T> addAllElements(Collection<? extends T> p_newC) {
    	addAll(p_newC);
    	return this;
    }

    @Override
    public boolean containsElement(Object p_element) {
        return contains(p_element);
    }

    @Override
    public boolean containsAllElements(Collection<?> p_c) {
        return containsAll(p_c);
    }

    @Override
    public T getElement(int index) {
        return null;
    }

    public Iterator<T> getIterator() {
        return iterator();
    }

    @Override
    public InnerSet<T> removeElement(Object p_element) {
        remove(p_element);
        return this;
    }

    @Override
    public InnerSet<T> removeAllElements(Collection<?> p_cToDelete) {
        removeAll(p_cToDelete);
        return null;
    }

    @Override
    public InnerSet<T> retainAllElements(Collection<?> p_cToKeep) {
        retainAll(p_cToKeep);
        return this;
    }

    @Override
    public int getSize() {
        return 0;
    }
    
    public static void main(String[] Args)
    {
    	InnerHashSet<Integer> inner_hash_set = new InnerHashSet<Integer>();
    	System.out.println(inner_hash_set.toString());
    	inner_hash_set.add(12);
    	System.out.println(inner_hash_set.toString());
    	inner_hash_set.add(42);
    	System.out.println(inner_hash_set.toString());
    	System.out.println(inner_hash_set.contains(42));
    	inner_hash_set.remove(12);
    	System.out.println(inner_hash_set.toString());
    }
}
