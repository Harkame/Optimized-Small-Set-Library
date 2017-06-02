#include "micro_inner_set.hpp"
#include "inner_unordered_set.hpp"
#include "iterator_micro_set.hpp"

#include "inner_set_0.hpp"

using namespace std;

template<typename T>
micro_inner_set<T>::micro_inner_set()
{
	this->a_inner_set = inner_set_0<T>::EMPTY;
}

template<typename T>
micro_inner_set<T>::~micro_inner_set()
{

}

template<typename T>
iterator_micro_set<T> micro_inner_set<T>::begin()
{
	return iterator_micro_set<T>(this->a_inner_set);
}

template<typename T>
iterator_micro_set<T>  micro_inner_set<T>::end()
{
	iterator_micro_set<T> r_iterator_micro_set(this->a_inner_set);

	return r_iterator_micro_set.end();
}

template<typename T>
iterator_micro_set<T> micro_inner_set<T>::find(T p_element)
{
	iterator_micro_set<T> r_iterator_micro_set(this->a_inner_set);

	while(r_iterator_micro_set != end())
		if(*r_iterator_micro_set == p_element)
			return r_iterator_micro_set;
		else
			r_iterator_micro_set++;

	return r_iterator_micro_set;
}

template<typename T>
bool micro_inner_set<T>::empty() const
{
    return this->a_inner_set->get_size() == 0;
}

template<typename T>
int micro_inner_set<T>::size() const
{
    return this->a_inner_set->get_size();
}

template<typename T>
int micro_inner_set<T>::max_size() const
{
	return -1; //Pas de taille max ?
}
template<typename T>
void micro_inner_set<T>:: insert(T p_element)
{
	this->a_inner_set = this->a_inner_set->add_element(p_element);
}

template<typename T>
void micro_inner_set<T>:: erase(T p_element)
{
	this->a_inner_set = this->a_inner_set->remove_element(p_element);
}

template<typename T>
void micro_inner_set<T>:: clear()
{
	if(this->a_inner_set == nullptr)
		this->a_inner_set = inner_set_0<T>::EMPTY;
	else if(this->a_inner_set->get_size() > 0)
	{
		delete this->a_inner_set;
		this->a_inner_set = inner_set_0<T>::EMPTY;
	}
}

template<typename T>
bool micro_inner_set<T>::retain_all(micro_inner_set<T> p_micro_inner_set)
{
	int t_size = size();

	this->a_inner_set = p_micro_inner_set.a_inner_set->retain_all_elements(this->a_inner_set);

	return this->a_inner_set->get_size() != t_size;
}

template<typename T>
void micro_inner_set<T>::add_all(micro_inner_set<T> p_micro_inner_set)
{
	micro_inner_set<T> t_micro_inner_set;
	iterator_micro_set<T> t_iterator_micro_set = this->begin();

	while(t_iterator_micro_set != t_iterator_micro_set.end())
		t_micro_inner_set.insert(*t_iterator_micro_set++);

	this->a_inner_set = p_micro_inner_set.a_inner_set->add_all_elements(t_micro_inner_set.a_inner_set);
}

template<typename T>
void micro_inner_set<T>::remove_all(micro_inner_set<T> p_micro_inner_set)
{
	this->a_inner_set = p_micro_inner_set.a_inner_set->remove_all_elements(this->a_inner_set);
}

template<typename T>
micro_inner_set<T> micro_inner_set<T>::add_all_and_propagate(micro_inner_set<T> p_micro_inner_set)
{
	micro_inner_set<T> r_micro_inner_set;

	this->a_inner_set = this->a_inner_set->add_all_and_propagate(p_micro_inner_set.a_inner_set, &r_micro_inner_set);

	return r_micro_inner_set;
}
