package j.implementation;

public class InnerSet_2<T> implements InnerSet<T>
{	
	private T element_0;
	private T element_1;
	
	
	public InnerSet_2()
	{
		
	}
	
	public InnerSet_2(T p_element_0, T p_element_1)
	{
		element_0 = p_element_0;
		element_1 = p_element_1;
	}
	
	@Override
	public InnerSet<T>addElement(T p_element)
	{
		if(element_0.equals(p_element))
			return this;
		else if(element_1.equals(p_element))
			return this;
		else
			//return new InnerSet_2(p_element);
			return null;
	}

	@Override
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public InnerSet<T> removeElement(T p_element)
	{
		if(element_0.equals(p_element))
			return new InnerSet_1(element_1);
		else if(element_1.equals(p_element))
			return new InnerSet_1(element_0);
		else
			return this;
	}
	
	@Override
	public String toString()
	{
		StringBuilder string_builder = new StringBuilder();
		
		string_builder.append("{");
		
		string_builder.append(element_0);
		
		string_builder.append(", ");
		
		string_builder.append(element_1);
		
		string_builder.append("}");
		
		return string_builder.toString();
	}
	
	public static void main(String [] Args)
	{
		InnerSet<Integer> inner_set_0 = null;
		InnerSet<Integer> inner_set_1 = null;
		InnerSet<Integer> inner_set_2 = null;
		
		inner_set_0 = new InnerSet_0<Integer>();
		System.out.println(inner_set_0.toString() + " - " + inner_set_0.getClass().getName());
		
		inner_set_1 = inner_set_0.addElement(12);
		System.out.println(inner_set_1.toString() + " - " + inner_set_1.getClass().getName());
		
		inner_set_2 = inner_set_1.addElement(13);
		System.out.println(inner_set_2.toString() + " - " + inner_set_2.getClass().getName());
		
		inner_set_1 = inner_set_2.removeElement(12);
		System.out.println(inner_set_1.toString() + " - " + inner_set_1.getClass().getName());
		
		inner_set_0 = inner_set_1.removeElement(13);
		System.out.println(inner_set_0.toString() + " - " + inner_set_0.getClass().getName());
	}
}
