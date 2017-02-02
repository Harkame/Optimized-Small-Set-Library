package j.implementation.innerSet;

public class InnerSet_1<T> implements InnerSet<T>
{	
	private int size;

	public T element_0;
	
	public InnerSet_1()
	{
		size = 1;
	}
	
	public InnerSet_1(T p_element)
	{
		element_0 = p_element;
	}

	@Override
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public InnerSet<T>addElement(T p_element)
	{
		if(element_0.equals(p_element))
			return this;
		else
			return new InnerSet_2(this, p_element);
	}

	@Override
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public InnerSet<T> removeElement(T p_element)
	{
		if(element_0.equals(p_element))
				return new InnerSet_0();
		else
			return this;
	}

	@Override
	public boolean containsElement(T p_element)
	{
		return element_0.equals(p_element);
	}
	
	@Override
	public String toString()
	{
		StringBuilder string_builder = new StringBuilder();
		
		string_builder.append("{");
		
		string_builder.append(element_0);
		
		string_builder.append("}");
		
		return string_builder.toString();
	}
	
	@Override
	public int getSize()
	{
		return size;
	}
}
