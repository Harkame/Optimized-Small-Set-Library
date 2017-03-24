#include "micro_hashset.hpp"

using namespace std;

template<typename T>
micro_hashset<T>::micro_hashset()
{
	a_inner_set = new inner_hashset<T>();
}

template<typename T>
micro_hashset<T>::~micro_hashset()
{

}

/* Operator */
/*
template<typename T>
micro_hashset<T> micro_hashset<T>::operator=(micro_hashset<T> p_micro_hashset)
{
	//TODO
	micro_hashset<T>* r_micro_hashset = new micro_hashset<T>(){}

	return r_micro_hashset;
}
*/

/* Iterators */

template<typename T>
void micro_hashset<T>::begin()
{

}

template<typename T>
void micro_hashset<T>::end()
{

}

template<typename T>
void micro_hashset<T>::rbegin()
{

}

template<typename T>
void micro_hashset<T>::rend()
{

}

template<typename T>
void micro_hashset<T>::cbegin()
{

}

template<typename T>
void micro_hashset<T>::cend()
{

}

template<typename T>
void micro_hashset<T>::crbegin()
{

}

template<typename T>
void micro_hashset<T>::crend()
{

}

template<typename T>
bool micro_hashset<T>::empty() const
{
    return a_inner_set->get_size() == 0;
}

template<typename T>
int micro_hashset<T>::size() const
{
    return a_inner_set->get_size();
}

template<typename T>
int micro_hashset<T>::max_size() const
{
	return -1; //Pas de taille max ?
}

/* Modifiers */

template<typename T>
void micro_hashset<T>:: insert(){}

template<typename T>
void micro_hashset<T>:: erase(){}

template<typename T>
void micro_hashset<T>:: swap(){}

template<typename T>
void micro_hashset<T>:: clear(){}

template<typename T>
void micro_hashset<T>:: emplace(){}

template<typename T>
void micro_hashset<T>:: emplace_hint(){}

/* Observers */ //TODO

/* Operations */
/*
template<typename T>
void micro_hashset<T>:: find()
{

}

template<typename T>
void micro_hashset<T>:: count()
{

}
*/

template<typename T>
void micro_hashset<T>:: lower_bound(){}

template<typename T>
void micro_hashset<T>:: upper_bound(){}

template<typename T>
void micro_hashset<T>:: equal_range(){}

/* Allocator */

template<typename T>
void micro_hashset<T>:: get_allocator(){}

int main()
{
	micro_hashset<int>* ms = new micro_hashset<int>();

	return 0;
}
