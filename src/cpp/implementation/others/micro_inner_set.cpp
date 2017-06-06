#include "micro_inner_set.hpp"
#include "inner_unordered_set.hpp"
#include "iterator_micro_set.hpp"

#include "inner_set_0.hpp"

using namespace std;

template<typename T>
micro_array_set<T>::micro_array_set()
{
	this->a_inner_set = new inner_array_set<T>();
}

template<typename T, int p_to_up>
micro_array_set<T>::~micro_array_set()
{

}

template<typename T, int p_to_up>
iterator_micro_array_set<T> micro_array_set<T>::begin() const
{
	return iterator_micro_array_set<T>(a_inner_set);
}

template<typename T, int p_to_up>
iterator_micro_array_set<T>  micro_array_set<T>::end() const
{
	iterator_micro_array_set<T> r_iterator_micro_array_set(a_inner_set);

	return r_iterator_micro_array_set.end();
}

template<typename T, int p_to_up>
iterator_micro_array_set<T> micro_array_set<T>::find(T p_element) const
{
	iterator_micro_array_set<T> r_iterator_micro_array_set(a_inner_set);

	while(r_iterator_micro_array_set != end())
		if(*r_iterator_micro_array_set == p_element)
			return r_iterator_micro_array_set;
		else
			r_iterator_micro_array_set++;

	return r_iterator_micro_array_set;
}

template<typename T, int p_to_up>
bool micro_array_set<T>::empty() const
{
    return a_inner_set->get_size() == 0;
}

template<typename T, int p_to_up>
int micro_array_set<T>::size() const
{
    return a_inner_set->get_size();
}

template<typename T, int p_to_up>
void micro_array_set<T>:: insert(T p_element)
{
	a_inner_set = a_inner_set->add_element(p_element);
}

template<typename T, int p_to_up>
void micro_array_set<T>::insert_all(micro_array_set<T> p_micro_array_set)
{
	a_inner_set = p_micro_array_set.a_inner_set->add_all_elements(a_inner_set);
}

template<typename T, int p_to_up>
void micro_array_set<T>:: erase(T p_element)
{
	a_inner_set = a_inner_set->remove_element(p_element);
}

template<typename T, int p_to_up>
void micro_array_set<T>::erase_all(micro_array_set<T> p_micro_array_set)
{
	a_inner_set = p_micro_array_set.a_inner_set->remove_all_elements(a_inner_set);
}

template<typename T, int p_to_up>
void micro_array_set<T>::retain_all(micro_array_set<T> p_micro_array_set)
{
	a_inner_set = p_micro_array_set.a_inner_set->retain_all_elements(a_inner_set);
}

template<typename T, int p_to_up>
void micro_array_set<T>:: clear()
{
	delete a_inner_set;

	this->a_inner_set = inner_set_0<T>::EMPTY;
}

template<typename T, int p_to_up>
micro_array_set<T>* micro_array_set<T>::add_all_and_propagate(micro_array_set<T> p_micro_array_set)
{
	micro_array_set<T>* r_micro_array_set = new micro_array_set<T>();

	this->a_inner_set = this->a_inner_set->add_all_and_propagate(p_micro_array_set.a_inner_set, r_micro_array_set);

	return r_micro_array_set;
}

template<typename T, int p_to_up>
bool  operator==(const micro_array_set<T> p_micro_array_set_a, const micro_array_set<T> p_micro_array_set_b)
{
	return true;
}
