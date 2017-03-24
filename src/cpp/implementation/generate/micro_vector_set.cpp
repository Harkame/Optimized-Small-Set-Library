#include "micro_vector_set.hpp"

using namespace std;

template<typename T>
micro_set<T>::micro_set()
{
	a_inner_vector_set = new inner_vector_set<T>();
}

template<typename T>
micro_set<T>::~micro_set()
{

}

/* Operator */
/*
template<typename T>
micro_set<T> micro_set<T>::operator=(micro_set<T> p_micro_set)
{
	//TODO
	micro_set<T>* r_micro_set = new micro_set<T>(){}

	return r_micro_set;
}
*/

/* Iterators */

template<typename T>
void micro_set<T>::begin()
{

}

template<typename T>
void micro_set<T>::end()
{

}

template<typename T>
void micro_set<T>::rbegin()
{

}

template<typename T>
void micro_set<T>::rend()
{

}

template<typename T>
void micro_set<T>::cbegin()
{

}

template<typename T>
void micro_set<T>::cend()
{

}

template<typename T>
void micro_set<T>::crbegin()
{

}

template<typename T>
void micro_set<T>::crend()
{

}

template<typename T>
bool micro_set<T>::empty() const
{
    return a_inner_set->get_size() == 0;
}

template<typename T>
int micro_set<T>::size() const
{
    return a_inner_set->get_size();
}

template<typename T>
int micro_set<T>::max_size() const
{
	return -1; //Pas de taille max ?
}

/* Modifiers */

template<typename T>
void micro_set<T>:: insert(){}

template<typename T>
void micro_set<T>:: erase(){}

template<typename T>
void micro_set<T>:: swap(){}

template<typename T>
void micro_set<T>:: clear(){}

template<typename T>
void micro_set<T>:: emplace(){}

template<typename T>
void micro_set<T>:: emplace_hint(){}

/* Observers */ //TODO

/* Operations */
/*
template<typename T>
void micro_set<T>:: find()
{

}

template<typename T>
void micro_set<T>:: count()
{

}
*/

template<typename T>
void micro_set<T>:: lower_bound(){}

template<typename T>
void micro_set<T>:: upper_bound(){}

template<typename T>
void micro_set<T>:: equal_range(){}

/* Allocator */

template<typename T>
void micro_set<T>:: get_allocator(){}

int main()
{
	micro_vector_set<int>* ms = new micro_vector_set<int>();

	return 0;
}
