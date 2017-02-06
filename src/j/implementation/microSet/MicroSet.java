package j.implementation.microSet;

import java.util.Collection;
import java.util.Iterator;
import java.util.Set;

public class MicroSet<T> implements Set<T>
{
	private InnerSet<T> inner_set;

	@Override
	public boolean add(T e)
	{
		InnerSet<T> oldInnerSet = this.inner_set;
		this.inner_set = this.inner_set.addElement(e);
		return oldInnerSet.getSize() == (this.inner_set.getSize() + 1);
	}

	/**
	 * @return true if this.innerSet has been changed after the call
	 */
	@Override
	public boolean addAll(Collection<? extends T> c)
	{
		InnerSet<T> oldInnerSet = this.inner_set;
		this.inner_set = this.inner_set.addAllElements(c);
		return this.inner_set.getSize() != oldInnerSet.getSize();
	}

	@Override
	public void clear()
	{
		this.inner_set = (InnerSet_0<T>) InnerSet_0.singleton;
	}

	@Override
	public boolean contains(Object o)
	{
		return this.inner_set.containsElement(o);
	}

	@Override
	public boolean containsAll(Collection<?> c)
	{
		return this.inner_set.containsAllElements(c);
	}

	@Override
	public boolean isEmpty()
	{
		return this.inner_set.getSize() == 0;
	}

    @Override
	public Iterator<T> iterator()
	{
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean remove(Object o)
	{
        InnerSet<T> oldInnerSet = this.inner_set;
        this.inner_set = this.inner_set.removeElement(o);
        return oldInnerSet.getSize() == (this.inner_set.getSize() - 1);
	}

    /**
     * @return true if this.innerSet has been changed after the call
     */
	@Override
	public boolean removeAll(Collection<?> c)
	{
        InnerSet<T> oldInnerSet = this.inner_set;
        this.inner_set = this.inner_set.removeAllElements(c);
        return this.inner_set.getSize() != oldInnerSet.getSize();
	}

	@Override
	public boolean retainAll(Collection<?> c)
	{
        InnerSet<T> oldInnerSet = this.inner_set;
        this.inner_set = this.inner_set.retainAllElements(c);
        return this.inner_set.getSize() != oldInnerSet.getSize();
	}

	@Override
	public int size()
	{
		return this.inner_set.getSize();
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
