package j.implementation.microSet;

import java.util.Iterator;

public class InnerSetIterator<T> implements Iterator<T>
{
	private int index = 0;
	private InnerSet innerSet;
	
	public InnerSetIterator(InnerSet<T> p_innerSet)
	{
		innerSet = p_innerSet;
	}

	@Override
	public boolean hasNext()
	{
		return index != innerSet.getSize();
	}

	@Override
	public T next()
	{
		return (T) innerSet.getElement(index++);
	}
}
