package j.implementation.other;

import java.util.Iterator;

public class InnerSetIterator implements Iterator<Object>
{
	private int index = 1;
	private InnerSet innerSet;
	
	public InnerSetIterator(InnerSet p_innerSet)
	{
		innerSet = p_innerSet;
	}

	@Override
	public boolean hasNext()
	{
		return index != innerSet.getSize();
	}

	@Override
	public Object next()
	{
		return innerSet.getElement(index++);
	}
}
