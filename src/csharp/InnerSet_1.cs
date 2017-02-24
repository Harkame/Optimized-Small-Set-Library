using System;
namespace OSSL
{
	public class InnerSet_1<T> : InnerSet<T>
	{
		public T a_element_1
		{
			get
			{
				return a_element_1;
			}
			set
			{
				a_element_1 = value;
			}
		}

		public InnerSet_1()
		{
		}

		public InnerSet_1(T p_element)
		{
			a_element_1 = p_element;
		}

		public InnerSet<T> addElement(T p_element)
		{
			if (p_element.Equals(a_element_1))
				return new InnerSet_2<T>(this, p_element);
			else
				return this;
		}

		public InnerSet<T> removeElement(T p_element)
		{
			if (a_element_1.Equals(p_element))
				return new InnerSet_0<T>();
			else
				return this;
		}
	}
}
