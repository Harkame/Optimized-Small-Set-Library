package j.implementation.innerSet;

public interface InnerSet<T>
{
	public InnerSet<T> addElement(T p_element);
	
	public InnerSet<T> removeElement(T p_element);
	
	public int getSize();
}