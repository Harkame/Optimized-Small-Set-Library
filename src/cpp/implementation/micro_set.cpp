#include "micro_set.h"

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

virtual void begin()
{

}

virtual void end();

virtual void rbegin();

virtual void rend();

virtual void cbegin();

virtual void cend();

virtual void crbegin();

virtual void crend();

/* Capacity */
template<typename T>
bool micro_set<T>::empty()
{
    return a_inner_set->get_size() == 0;
}

template<typename T>
int micro_set<T>::size()
{
    return a_inner_set->get_size();
}

template<typename T>
int micro_set<T>::max_size()
{
	return -1; //Pas de taille max ?
}

/* Modifiers */

virtual void insert();

virtual void erase();

virtual void swap();

virtual void clear();

virtual void emplace();

virtual void emplace_hint();

/* Observers */

virtual void key_comp();

virtual void value_comp();

/* Operations */

virtual void fin();

virtual void count();

virtual void lower_bound();

virtual void upper_bound();

virtual void equal_range();

/* Allocator */

virtual void get_allocator();
