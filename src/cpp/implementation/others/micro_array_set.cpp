#include "micro_array_set.hpp"

#include "../iterator_micro_set.hpp"

using namespace std;

template<typename T, int p_to_up>
micro_array_set<T, p_to_up>::micro_array_set()
{
	this->a_inner_set = new inner_array_set<T, p_to_up>();
}

template<typename T, int p_to_up>
micro_array_set<T, p_to_up>::~micro_array_set()
{

}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up> micro_array_set<T, p_to_up>::begin() const
{
	return iterator_micro_set<T, p_to_up>(a_inner_set);
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up>  micro_array_set<T, p_to_up>::end() const
{
	iterator_micro_set<T, p_to_up> r_iterator_micro_set(a_inner_set);

	return r_iterator_micro_set.end();
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up> micro_array_set<T, p_to_up>::find(T p_element) const
{
	iterator_micro_set<T, p_to_up> r_iterator_micro_set(a_inner_set);

	while(r_iterator_micro_set != end())
		if(*r_iterator_micro_set == p_element)
			return r_iterator_micro_set;
		else
			r_iterator_micro_set++;

	return r_iterator_micro_set;
}

template<typename T, int p_to_up>
bool micro_array_set<T, p_to_up>::empty() const
{
    return a_inner_set->get_size() == 0;
}

template<typename T, int p_to_up>
int micro_array_set<T, p_to_up>::size() const
{
    return a_inner_set->get_size();
}

template<typename T, int p_to_up>
void micro_array_set<T, p_to_up>:: insert(T p_element)
{
	a_inner_set = a_inner_set->add_element(p_element);
}

template<typename T, int p_to_up>
void micro_array_set<T, p_to_up>::insert_all(micro_array_set<T, p_to_up> p_micro_array_set)
{
	a_inner_set = p_micro_array_set.a_inner_set->add_all_elements(a_inner_set);
}

template<typename T, int p_to_up>
void micro_array_set<T, p_to_up>:: erase(T p_element)
{
	a_inner_set = a_inner_set->remove_element(p_element);
}

template<typename T, int p_to_up>
void micro_array_set<T, p_to_up>::erase_all(micro_array_set<T, p_to_up> p_micro_array_set)
{
	a_inner_set = p_micro_array_set.a_inner_set->remove_all_elements(a_inner_set);
}

template<typename T, int p_to_up>
void micro_array_set<T, p_to_up>::retain_all(micro_array_set<T, p_to_up> p_micro_array_set)
{
	a_inner_set = p_micro_array_set.a_inner_set->retain_all_elements(a_inner_set);
}

template<typename T, int p_to_up>
void micro_array_set<T, p_to_up>:: clear()
{
	if(a_inner_set != nullptr)
		if(a_inner_set->get_size() != 0)
			delete a_inner_set;

	this->a_inner_set = new inner_array_set<T, p_to_up>();
}

template<typename T, int p_to_up>
micro_array_set<T, p_to_up>* micro_array_set<T, p_to_up>::add_all_and_propagate(micro_array_set<T, p_to_up> p_micro_array_set)
{
	micro_array_set<T, p_to_up>* r_micro_array_set = new micro_array_set<T, p_to_up>();

	this->a_inner_set = this->a_inner_set->add_all_and_propagate(p_micro_array_set.a_inner_set, r_micro_array_set);

	return r_micro_array_set;
}

template<typename T, int p_to_up>
bool  operator==(const micro_array_set<T, p_to_up> p_micro_array_set_a, const micro_array_set<T, p_to_up> p_micro_array_set_b)
{
	return true;
}
