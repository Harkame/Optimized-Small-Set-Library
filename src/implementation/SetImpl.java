package implementation;

import java.util.Collection;
import java.util.Iterator;
import java.util.Set;

//TODO Implement
public final class SetImpl<T> implements Set <T>
{	
	@Override
	public boolean add(T e)
	{
		return false;
	}

	@Override
	public boolean addAll(Collection<? extends T> c)
	{
		return false;
	}

	@Override
	public void clear()
	{
	}

	@Override
	public boolean contains(Object o)
	{
		return false;
	}

	@Override
	public boolean containsAll(Collection<?> c)
	{
		return false;
	}

	@Override
	public boolean isEmpty()
	{
		return false;
	}

	@Override
	public Iterator<T> iterator()
	{
		return null;
	}

	@Override
	public boolean remove(Object o)
	{
		return false;
	}

	@Override
	public boolean removeAll(Collection<?> c)
	{
		return false;
	}

	@Override
	public boolean retainAll(Collection<?> c)
	{
		return false;
	}

	@Override
	public int size()
	{
		return 0;
	}

	@Override
	public Object[] toArray()
	{
		return null;
	}


	@Override
	@SuppressWarnings("hiding")
	public <T> T[] toArray(T[] a)
	{
		return null;
	}
}
