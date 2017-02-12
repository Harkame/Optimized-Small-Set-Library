package j.implementation.microSet;

import java.util.Collection;

public class InnerSet_2<T> implements InnerSet<T>
{	
	protected T element_0;
	protected T element_1;
	
	public InnerSet_2()
	{
	}
	
	public InnerSet_2(T p_element_0, T p_element_1)
	{
		element_0 = p_element_0;
		element_1 = p_element_1;
	}
	
	@Override
	public InnerSet<T> addElement(T p_element)
	{
		if(element_0.equals(p_element) ||
				element_1.equals(p_element))
			return this;
		else
			//return new InnerSet_2(p_element);
			return null;
	}

	@Override
	public InnerSet<T> addAllElements(Collection<? extends T> p_newC) {
		return null;
	}

	@Override
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public InnerSet<T> removeElement(Object p_element)
	{
		if (element_0.equals(p_element))
			return new InnerSet_1(element_1);
		else if (element_1.equals(p_element))
			return new InnerSet_1(element_0);
		else
			return this;
	}

	@Override
	public InnerSet<T> removeAllElements(Collection<?> p_cToDelete) {
		return null;
	}

	@Override
	public InnerSet<T> retainAllElements(Collection<?> p_cToKeep) {
		return null;
	}

	@Override
	public boolean containsElement(Object p_element)
	{
		return element_0.equals(p_element) ||
			   element_1.equals(p_element);
	}

	@Override
	public boolean containsAllElements(Collection<?> p_c) {
		return false;
	}

	public T getElement(int index)
	{
		if (index == 0)
			return element_0;
		else if (index == 1)
			return element_1;
		else
			return null;
	}

	@Override
	public String toString()
	{
		return "{" + element_0 + ", " + element_1 + "}";
	}
	
	@Override
	public int getSize()
	{
		return 2;
	}
}
