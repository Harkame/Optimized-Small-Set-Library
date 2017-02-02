package j.implementation.innerSet;

import java.lang.reflect.Array;

public class InnerSet_0 <T> implements InnerSet<T>
{
	private int size;

	public InnerSet_0()
	{
		size = 0;
	}
	
	@Override
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public InnerSet<T> addElement(T p_element)
	{
		return new InnerSet_1(p_element);
	}

	@Override
	public InnerSet<T> removeElement(T p_element)
	{
		return this;
	}
	
	@Override
	public String toString()
	{
		StringBuilder string_builder = new StringBuilder();
		
		string_builder.append("{");
		
		string_builder.append("}");
		
		return string_builder.toString();
	}
	
	@Override
	public int getSize()
	{
		return size;
	}

	@Override
	public boolean containsElement(T p_element)
	{
		// TODO Auto-generated method stub
		return false;
	}
}
