package j.implementation.microSet;

public interface InnerSet<T>
{
	InnerSet<T> addElement(T p_element);

	InnerSet<T> removeElement(Object p_element);

	int getSize();

	boolean containsElement(Object p_element);
}
