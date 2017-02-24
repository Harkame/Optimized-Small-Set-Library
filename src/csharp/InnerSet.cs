using System;
namespace OSSL
{
	public interface InnerSet<T>
	{
		InnerSet<T> addElement(T p_element);

		InnerSet<T> removeElement(T p_element);
	}
}
