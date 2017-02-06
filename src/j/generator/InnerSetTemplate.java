package j.implementation.microSet;

public class InnerSet_inneroffset<T> implements InnerSet<T>
{
	// for inneroffset
	protected T element_inneroffset;
	// end

	public InnerSet_inneroffset()
	{

	
	public InnerSet_inneroffset(/* for inneroffset separator=','*/T p_element_offset/* end */)
	{
		// for inneroffset
		element_offset = p_element_offset;
		// end
	}
	
	@Override
	public InnerSet<T> addElement(T p_element)
	{
		if(/* for inneroffset separator='||'*/element_offset.equals(p_element)/* end */)
			return this;
		else
			return new InnerSet_inneroffsetplus(p_element);
	}

	@Override
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public InnerSet<T> removeElement(Object p_element)
	{
		/* for inneroffset separator='else'*/
		if(element_offset.equals(p_element))
			return new InnerSet_inneroffsetless(element_1); // TODO
		/* end */
		else
			return this;
	}

	@Override
	public boolean containsElement(Object p_element)
	{
		return /* for inneroffset separator='||'*/element_offset.equals(p_element)/* end */;
	}

	@Override
	public String toString()
	{
		return "{ }"
	}
	
	@Override
	public int getSize()
	{
		return inneroffset;
	}

}
