package j.implementation.microSet;

import j.implementation.microSet.InnerSet;
import j.implementation.microSet.InnerSet_0;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.Set;

public class MicroSet<T> implements Set<T>
{
	private InnerSet<T> inner_set;

	@Override
	public boolean add(T e)
	{
		InnerSet<T> temp = this.inner_set;
		this.inner_set = this.inner_set.addElement(e);
		return temp.getSize() == (this.inner_set.getSize() + 1);
	}

	@Override
	public boolean addAll(Collection<? extends T> c)
	{
		// TODO Titou
		return false;
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
		// TODO Auto-generated method stub
		return false;
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
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean removeAll(Collection<?> c)
	{
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean retainAll(Collection<?> c)
	{
		// TODO Auto-generated method stub
		return false;
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
