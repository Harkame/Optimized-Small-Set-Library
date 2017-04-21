#include "micro_unordered_set.hpp"

using namespace std;

template<typename T>
micro_unordered_set<T>::micro_unordered_set()
{
	a_inner_set = new inner_unordered_set<T>();
}

template<typename T>
micro_unordered_set<T>::~micro_unordered_set()
{

}

template<typename T>
iterator_inner_set<T>* micro_unordered_set<T>::begin()
{
	return new iterator_inner_set<T>(a_inner_set);
}

template<typename T>
iterator_inner_set<T>* micro_unordered_set<T>::end()
{
	iterator_inner_set<T>* r_iterator_inner_set = new iterator_inner_set<T>(a_inner_set);

	r_iterator_inner_set->set_end();

	return r_iterator_inner_set;
}

template<typename T>
bool micro_unordered_set<T>::empty() const
{
    return a_inner_set->get_size() == 0;
}

template<typename T>
int micro_unordered_set<T>::size() const
{
    return a_inner_set->get_size();
}

template<typename T>
int micro_unordered_set<T>::max_size() const
{
	return -1; //Pas de taille max ?
}

template<typename T>
void micro_unordered_set<T>:: insert(T p_element)
{
	a_inner_set = a_inner_set->add_element(p_element);
}

template<typename T>
void micro_unordered_set<T>:: erase(T p_element)
{
	a_inner_set->remove_element(p_element);
}

template<typename T>
void micro_unordered_set<T>:: clear()
{
	delete a_inner_set;

	a_inner_set = new inner_unordered_set<T>();
}

template<typename T>
bool micro_unordered_set<T>::retain_all(micro_unordered_set<T> p_micro_unordered_set)
{
	int t_size = size();

	a_inner_set = p_micro_unordered_set.a_inner_set->retain_all_elements(a_inner_set);

	return a_inner_set->get_size() != t_size;
}
