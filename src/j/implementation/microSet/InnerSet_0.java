package j.implementation.microSet;

public class InnerSet_0 <T> implements InnerSet<T>
{
	static InnerSet_0<Object> singleton = new InnerSet_0<>();
	
	@Override
	public InnerSet<T> addElement(T p_element)
	{
		return new InnerSet_1(p_element);
	}

	@Override
	public InnerSet<T> removeElement(Object p_element)
	{
		return this;
	}

	protected T getElement(int index)
	{
		return null;
	}
	
	@Override
	public String toString()
	{
		return "{}";
	}
	
	@Override
	public int getSize()
	{
		return 0;
	}

	@Override
	public boolean containsElement(Object p_element)
	{
		return false;
	}
}
