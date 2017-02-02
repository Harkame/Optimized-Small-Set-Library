package j.implementation.innerSet;

public interface InnerSet<T>
{
	InnerSet<T> addElement(T p_element);

	InnerSet<T> removeElement(T p_element);

	int getSize();

	boolean containsElement(T p_element);
}
