#include "micro_set.hpp"

using namespace std;

template<typename T>
micro_set<T>::micro_set()
{
	a_inner_set = inner_set_0<T>::INNER_SET_0;
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
	micro_set<T>* r_micro_set = new micro_set<T>();

	return r_micro_set;
}
*/

/* Iterators */

void begin()
{

}

void end();

void rbegin();

void rend();

void cbegin();

void cend();

void crbegin();

void crend();

/* Capacity */
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

void insert();

void erase();

void swap();

void clear();

void emplace();

void emplace_hint();

/* Observers */ //TODO

/* Operations */

void find()
{

}

void count()
{

}

void lower_bound();

void upper_bound();

void equal_range();

/* Allocator */

void get_allocator();
