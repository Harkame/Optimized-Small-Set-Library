package j.implementation.microSet;


import java.util.Collection;
import java.util.Iterator;
import java.util.Set;

public class MicroSet<T> implements Set<T>
{
	private InnerSet<T> innerSet;

	@Override
	public boolean add(T e)
	{
		InnerSet<T> oldInnerSet = this.innerSet;
		this.innerSet = this.innerSet.addElement(e);
		return oldInnerSet.getSize() == (this.innerSet.getSize() + 1);
	}

	/**
	 * @return true if this.innerSet has been changed after the call
	 */
	@Override
	public boolean addAll(Collection<? extends T> c)
	{
		InnerSet<T> oldInnerSet = this.innerSet;
		this.innerSet = this.innerSet.addAllElements(c);
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
		return this.innerSet.containsAllElements(c);
	}

	@Override
	public boolean isEmpty()
	{
		return this.innerSet.getSize() == 0;
	}

    @Override
	public Iterator<T> iterator()
	{
		return new InnerSetIterator<>(this.innerSet);
	}

	@Override
	public boolean remove(Object o)
	{
        InnerSet<T> oldInnerSet = this.innerSet;
        this.innerSet = this.innerSet.removeElement(o);
        return oldInnerSet.getSize() == (this.innerSet.getSize() - 1);
	}

    /**
     * @return true if this.innerSet has been changed after the call
     */
	@Override
	public boolean removeAll(Collection<?> c)
	{
        InnerSet<T> oldInnerSet = this.innerSet;
        this.innerSet = this.innerSet.removeAllElements(c);
        return this.innerSet.getSize() != oldInnerSet.getSize();
	}

	@Override
	public boolean retainAll(Collection<?> c)
	{
        InnerSet<T> oldInnerSet = this.innerSet;
        this.innerSet = this.innerSet.retainAllElements(c);
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
