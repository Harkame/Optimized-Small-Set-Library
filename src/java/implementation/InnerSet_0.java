package implementation;

public class InnerSet_0 <T> implements InnerSet<T>
{
	public InnerSet_0()
	{
		
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
}
