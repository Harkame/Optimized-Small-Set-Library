#include "micro_vector_set.hpp"

using namespace std;

template<typename T>
micro_vector_set<T>::micro_vector_set()
{
	a_inner_set = new inner_vector_set<T>();
}

template<typename T>
micro_vector_set<T>::~micro_vector_set()
{

}

template<typename T>
iterator_inner_set<T> micro_vector_set<T>::begin()
{
	return iterator_inner_set<T>(a_inner_set);
}

template<typename T>
iterator_inner_set<T> micro_vector_set<T>::end()
{
	iterator_inner_set<T> r_iterator_inner_set(a_inner_set);

	r_iterator_inner_set.set_end();

	return r_iterator_inner_set;
}

template<typename T>
bool micro_vector_set<T>::empty() const
{
    return a_inner_set->get_size() == 0;
}

template<typename T>
int micro_vector_set<T>::size() const
{
    return a_inner_set->get_size();
}

template<typename T>
int micro_vector_set<T>::max_size() const
{
	return -1; //Pas de taille max ?
}

template<typename T>
void micro_vector_set<T>:: insert(T p_element)
{
	a_inner_set = a_inner_set->add_element(p_element);
}

template<typename T>
void micro_vector_set<T>:: erase(T p_element)
{
	a_inner_set->remove_element(p_element);
}

template<typename T>
void micro_vector_set<T>:: clear()
{
	delete a_inner_set;

	a_inner_set = new inner_vector_set<T>();
}

template<typename T>
bool micro_vector_set<T>::retain_all(micro_vector_set<T> p_micro_vector_set)
{
	int t_size = size();;

	a_inner_set = p_micro_vector_set.a_inner_set->retain_all_elements(a_inner_set);

	return a_inner_set->get_size() != t_size;
}
