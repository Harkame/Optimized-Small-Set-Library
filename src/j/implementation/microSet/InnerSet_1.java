package j.implementation.microSet;

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
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public InnerSet<T>addElement(T p_element)
	{
		if(element_0.equals(p_element))
			return this;
		else
			return new InnerSet_2(this.element_0, p_element);
	}

	@Override
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public InnerSet<T> removeElement(Object p_element)
	{
		if(element_0.equals(p_element))
			return new InnerSet_0();
		else
			return this;
	}

	@Override
	public boolean containsElement(Object p_element)
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
		return 1;
	}
}
