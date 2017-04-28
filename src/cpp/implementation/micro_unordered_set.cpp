#include "micro_unordered_set.hpp"

#include "iterator_inner_set.hpp"

using namespace std;

template<typename T>
micro_unordered_set<T>::micro_unordered_set()
{
	this->a_inner_set = new inner_unordered_set<T>();
}

template<typename T>
micro_unordered_set<T>::~micro_unordered_set()
{

}

template<typename T>
iterator_inner_set<T> micro_unordered_set<T>::begin()
{
	return iterator_inner_set<T>(this->a_inner_set);
}

template<typename T>
iterator_inner_set<T>  micro_unordered_set<T>::end()
{
	iterator_inner_set<T> r_iterator_inner_set(this->a_inner_set);

	r_iterator_inner_set.set_end();

	return r_iterator_inner_set;
}

template<typename T>
iterator_inner_set<T> micro_unordered_set<T>::find(T p_element)
{
	iterator_inner_set<T> r_iterator_inner_set(this->a_inner_set);

	while(r_iterator_inner_set != end())
		if(*r_iterator_inner_set == p_element)
			return r_iterator_inner_set;
		else
			r_iterator_inner_set++;

	return r_iterator_inner_set;
}

template<typename T>
bool micro_unordered_set<T>::empty() const
{
    return this->a_inner_set->get_size() == 0;
}

template<typename T>
int micro_unordered_set<T>::size() const
{
    return this->a_inner_set->get_size();
}

template<typename T>
int micro_unordered_set<T>::max_size() const
{
	return -1; //Pas de taille max ?
}
template<typename T>
void micro_unordered_set<T>:: insert(T p_element)
{
	this->a_inner_set = this->a_inner_set->add_element(p_element);
}

template<typename T>
void micro_unordered_set<T>:: erase(T p_element)
{
	this->a_inner_set = this->a_inner_set->remove_element(p_element);
}

template<typename T>
void micro_unordered_set<T>:: clear()
{
	delete this->a_inner_set;

	this->a_inner_set = new inner_unordered_set<T>();
}

template<typename T>
bool micro_unordered_set<T>::retain_all(micro_unordered_set<T> p_micro_unordered_set)
{
	int t_size = size();

	this->a_inner_set = p_micro_unordered_set.a_inner_set->retain_all_elements(this->a_inner_set);

	return this->a_inner_set->get_size() != t_size;
}

template<typename T>
void micro_unordered_set<T>::add_all(micro_unordered_set<T> p_micro_unordered_set)
{
	this->a_inner_set = p_micro_unordered_set.a_inner_set->add_all_elements(this->a_inner_set);
}

template<typename T>
void micro_unordered_set<T>::remove_all(micro_unordered_set<T> p_micro_unordered_set)
{
	this->a_inner_set = p_micro_unordered_set.a_inner_set->remove_all_elements(this->a_inner_set);
}

template<typename T>
micro_unordered_set<T>* micro_unordered_set<T>::add_all_and_propagate(micro_unordered_set<T> p_micro_unordered_set)
{
	micro_unordered_set<T>* r_micro_unordered_set = new micro_unordered_set<T>();

	this->a_inner_set = this->a_inner_set->add_all_and_propagate(p_micro_unordered_set.a_inner_set, r_micro_unordered_set);

	return r_micro_unordered_set;
}

template<typename T>
bool  operator==(const micro_unordered_set<T> p_micro_unordered_set_a, const micro_unordered_set<T> p_micro_unordered_set_b)
{

	return true;
}
