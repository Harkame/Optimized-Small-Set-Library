package j.implementation.microSet;

public class InnerSet_innersetoffset<T> implements InnerSet<T>
{
	// for innersetoffset
	protected T element_offset;
	// end

	public InnerSet_innersetoffset() {}

	
	public InnerSet_innersetoffset(/* for innersetoffset separator=',' */T p_element_offset/* end */)
	{
		// for innersetoffset
		element_offset = p_element_offset;
		// end
	}
	
	@Override
	public InnerSet<T> addElement(T p_element)
	{
		if(/* for innersetoffset separator='||'*/element_offset.equals(p_element)/* end */)
			return this;
		else
			return new InnerSet_innersetoffsetplus(p_element);
	}

	@Override
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public InnerSet<T> removeElement(Object p_element)
	{
		// for innersetoffset separator='else '
		if(element_offset.equals(p_element))
			return new InnerSet_innersetoffsetless(/* for innersetoffset separator=', ' except_current_offset */element_offset/* end */);
		// end
		else
			return this;
	}

	@Override
	public boolean containsElement(Object p_element)
	{
		return /* for innersetoffset separator='||'*/element_offset.equals(p_element)/* end */;
	}

	@Override
	public String toString()
	{
		return "{" + /* for innersetoffset separator='+", "+' */ element_offset.toString() /*end*/ + "}"
	}
	
	@Override
	public int getSize()
	{
		return innersetoffset;
	}

}
