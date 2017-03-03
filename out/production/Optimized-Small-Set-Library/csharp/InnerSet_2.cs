using System;
namespace OSSL
{
	public class InnerSet_2<T> : InnerSet<T>
	{
		public T a_element_1;
		public T a_element_2;
		
		public InnerSet_2(InnerSet_1<T> p_inner_set, T p_element)
		{
			a_element_1 = p_inner_set.a_element_1;
			a_element_2 = p_element;
		}

		public InnerSet<T> addElement(T p_element)
		{
			if (a_element_1.Equals(p_element) ||
			   a_element_2.Equals(p_element))
				return null;
			else
				return this;
		}

		public InnerSet<T> removeElement(T p_element)
		{
			if (a_element_1.Equals(p_element))
				return new InnerSet_1<T>(a_element_2);
			else if (a_element_2.Equals(p_element))
				return new InnerSet_1<T>(a_element_1);
			else
				return this;
		}

		static void main(string[] Args)
		{
			InnerSet_0<int> inner_set_0 = new InnerSet_0<int>();
			InnerSet_1<int> inner_set_1 = (InnerSet_1<int>) inner_set_0.addElement(12);
			InnerSet_2<int> inner_set_2 = (InnerSet_2<int>) inner_set_1.addElement(24);

			System.Console.WriteLine(inner_set_2.ToString());
		}
	}
}
