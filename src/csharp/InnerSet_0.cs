using System;
namespace OSSL
{
	public class InnerSet_0<T> : InnerSet<T>
	{
		public InnerSet_0()
		{
		}

		public InnerSet<T> addElement(T p_element)
		{
			return new InnerSet_1<T>(p_element);
		}

		public InnerSet<T> removeElement(T p_element)
		{
			return this;
		}
	}
}
