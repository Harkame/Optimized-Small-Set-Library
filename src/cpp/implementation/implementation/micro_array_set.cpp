#include "micro_array_set.hpp"

#include "inner_set_0.cpp"
#include "inner_set_1.cpp"
#include "inner_set_2.cpp"
#include "inner_set_3.cpp"
#include "inner_set_4.cpp"
#include "inner_set_5.cpp"

//#include "inner_hashset.cpp"
#include "inner_array_set.cpp"


using namespace std;

template<typename T>
micro_array_set<T>::micro_array_set()
{
	a_inner_set = new inner_array_set<T>();
}

template<typename T>
micro_array_set<T>::~micro_array_set()
{

}


template<typename T>
void micro_array_set<T>::begin()
{

}

template<typename T>
void micro_array_set<T>::end()
{

}

template<typename T>
void micro_array_set<T>::rbegin()
{

}

template<typename T>
void micro_array_set<T>::rend()
{

}

template<typename T>
void micro_array_set<T>::cbegin()
{

}

template<typename T>
void micro_array_set<T>::cend()
{

}

template<typename T>
void micro_array_set<T>::crbegin()
{

}

template<typename T>
void micro_array_set<T>::crend()
{

}

template<typename T>
bool micro_array_set<T>::empty() const
{
    return a_inner_set->get_size() == 0;
}

template<typename T>
int micro_array_set<T>::size() const
{
    return a_inner_set->get_size();
}

template<typename T>
int micro_array_set<T>::max_size() const
{
	return -1; //Pas de taille max ?
}

/* Modifiers */

template<typename T>
void micro_array_set<T>:: insert(){}

template<typename T>
void micro_array_set<T>:: erase(){}

template<typename T>
void micro_array_set<T>:: swap(){}

template<typename T>
void micro_array_set<T>:: clear(){}

template<typename T>
void micro_array_set<T>:: emplace(){}

template<typename T>
void micro_array_set<T>:: emplace_hint(){}

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
void micro_array_set<T>:: lower_bound(){}

template<typename T>
void micro_array_set<T>:: upper_bound(){}

template<typename T>
void micro_array_set<T>:: equal_range(){}

/* Allocator */

template<typename T>
void micro_array_set<T>:: get_allocator(){}

int main()
{
	micro_array_set<int>* ms = new micro_array_set<int>();

	return 0;
}
