package j.implementation.microSet;


import javafx.beans.Observable;

import java.util.Collection;
import java.util.Iterator;
import java.util.Set;

public class MicroSet<T> implements Set<T>
{
	private InnerSet<T> innerSet;

	public MicroSet(InnerSet<T> innerSet) {
		if (innerSet instanceof InnerHashSet) {
			this.innerSet = new InnerHashSet<>(innerSet);
		} else {
			this.innerSet = innerSet;
		}
	}

	public MicroSet() {
		this.innerSet = new InnerSet_0<>();
	}

	@Override
	public boolean add(T e)
	{
		InnerSet<T> oldInnerSet = this.innerSet;
		this.innerSet = this.innerSet.addElement(e);
		return (oldInnerSet.getSize() + 1) == this.innerSet.getSize();
	}

	/**
	 * @return true if this.innerSet has been changed after the call
	 */
	@Override
	public boolean addAll(Collection<? extends T> collection)
	{
		InnerSet<T> oldInnerSet = this.innerSet;
		for (T el : collection) {
			innerSet = innerSet.addElement(el);
		}
		return this.innerSet.getSize() != oldInnerSet.getSize();
	}

	public boolean addAll(MicroSet<T> microSet) {
		InnerSet<T> oldInnerSet = this.innerSet;
		this.innerSet = microSet.innerSet.addAllElements(oldInnerSet);
		return this.innerSet.getSize() != oldInnerSet.getSize();
	}

	@Override
	public void clear()
	{
		this.innerSet = (InnerSet_0<T>) InnerSet_0.singleton;
	}

	@Override
	public boolean contains(Object o)
	{
		return this.innerSet.containsElement(o);
	}

	@Override
	public boolean containsAll(Collection<?> c)
	{
		for (Object el : c) {
			if(!innerSet.containsElement((T)el)){
				return false;
			}
		}
		return true;
	}

	public boolean containsAll(MicroSet<T> microSet){
		return microSet.innerSet.containsAllElements(innerSet);
	}

	@Override
	public boolean isEmpty()
	{
		return this.innerSet.getSize() == 0;
	}

    @Override
	public Iterator<T> iterator()
	{
		return this.innerSet.getIterator();
	}

	@Override
	public boolean remove(Object o)
	{
        InnerSet<T> oldInnerSet = this.innerSet;
        this.innerSet = this.innerSet.removeElement(o);
        return (oldInnerSet.getSize() - 1) == this.innerSet.getSize();
	}

    /**
     * @return true if this.innerSet has been changed after the call
     */
	@Override
	public boolean removeAll(Collection<?> c)
	{
        InnerSet<T> oldInnerSet = this.innerSet;
        for (Object el : c) {
            innerSet = innerSet.removeElement(el);
        }
        return this.innerSet.getSize() != oldInnerSet.getSize();
	}


	public boolean removeAll(MicroSet<T> microSet)
	{
		InnerSet<T> oldInnerSet = this.innerSet;
		this.innerSet = microSet.innerSet.removeAllElements(oldInnerSet);
		return this.innerSet.getSize() != oldInnerSet.getSize();
	}

	@Override
	public String toString() {
		return "MicroSet{" +
				"innerSet=" + innerSet +
				'}';
	}


	@Override
	public boolean retainAll(Collection<?> c)
	{
        InnerSet<T> oldInnerSet = this.innerSet;
        this.innerSet = new InnerSet_0<T>();
        for (Object el : c) {
            if(oldInnerSet.containsElement(el)){
                this.innerSet = this.innerSet.addElement((T) el);
            }
        }
        return this.innerSet.getSize() != oldInnerSet.getSize();
	}


	public boolean retainAll(InnerSet<T> innerSet)
	{
		InnerSet<T> oldInnerSet = this.innerSet;
		this.innerSet = this.innerSet.retainAllElements(innerSet);
		return this.innerSet.getSize() != oldInnerSet.getSize();
	}

	@Override
	public int size()
	{
		return this.innerSet.getSize();
	}

	@Override
	public Object[] toArray()
	{
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public <T> T[] toArray(T[] a)
	{
		// TODO Auto-generated method stub
		return null;
	}

}
