using System.Collections.Generic;
using System.Collections;

namespace OSSL
{
	public class MicroSet<T> : ISet<T>
	{
		protected InnerSet<T> singleton_inner_set_0 = new InnerSet_0<T>();

		private InnerSet<T> a_inner_set;

		public MicroSet()
		{
			singleton_inner_set_0 = new InnerSet_0<T>();

			a_inner_set = singleton_inner_set_0;
		}

		bool ISet<T>.Add(T t)
		{
			return true;
		}

		void ICollection<T>.Add(T t)
		{
		}

		void ICollection<T>.Clear()
		{

		}

		bool ICollection<T>.Contains(T t)
		{
			return true;
		}

		bool ICollection<T>.IsReadOnly
		{
			get;
		}

		int ICollection<T>.Count
		{
			get;
		}

		void ICollection<T>.CopyTo(T[] p_t, int p_int)
		{

		}

		void ISet<T>.ExceptWith(IEnumerable<T> p_i)
		{

		}

		IEnumerator IEnumerable.GetEnumerator()
		{
			return null;
		}

		IEnumerator<T> IEnumerable<T>.GetEnumerator()
		{
			return null;
		}

		void ISet<T>.IntersectWith(IEnumerable<T> p_other)
		{

		}

		bool ISet<T>.IsProperSubsetOf(IEnumerable<T> p_t)
		{
			return true;
		}

		bool ISet<T>.IsProperSupersetOf(IEnumerable<T> t)
		{
			return true;
		}

		bool ISet<T>.IsSubsetOf(IEnumerable<T> throwger)
		{
			return true;
		}

		bool ISet<T>.IsSupersetOf(IEnumerable<T> t)
		{
			return true;
		}

		bool ISet<T>.Overlaps(IEnumerable<T> t)
		{
			return true;
		}

		bool ICollection<T>.Remove(T t)
		{
			return true;
		}

		bool ISet<T>.SetEquals(IEnumerable<T> t)
		{
			return true;
		}

		void ISet<T>.SymmetricExceptWith(IEnumerable<T> t)
		{

		}

		void ISet<T>.UnionWith(IEnumerable<T> t)
		{

		}
	}
}
