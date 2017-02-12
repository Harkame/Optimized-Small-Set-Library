package j.implementation.microSet;

import java.util.Collection;

public class InnerSet_1<T> implements InnerSet<T>
{	
	protected T element_0;
	
	// Supprimer les attributs public
	public InnerSet_1()
	{
	}
	
	public InnerSet_1(T p_element)
	{
		element_0 = p_element;
	}

	@Override
	public InnerSet<T>addElement(T p_element)
	{
		if(element_0.equals(p_element))
			return this;
		else
			return new InnerSet_2(this.element_0, p_element);
	}

	@Override
	public InnerSet<T> addAllElements(Collection<? extends T> p_newC) {
		return null;
	}

	@Override
	public InnerSet<T> removeElement(Object p_element)
	{
		if(element_0.equals(p_element))
			return new InnerSet_0();
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

	public T getElement(int index)
	{
		if (index == 0)
			return element_0;
		else
			return null;
	}

	@Override
	public boolean containsElement(Object p_element)
	{
		return element_0.equals(p_element);
	}

	@Override
	public boolean containsAllElements(Collection<?> p_c) {
		return false;
	}

	@Override
	public String toString()
	{
		return "{" + element_0 + "}";
	}
	
	@Override
	public int getSize()
	{
		return 1;
	}
}
