#include "micro_vector_set.hpp"
#include "inner_vector_set.hpp"

#include "../iterator_micro_set.hpp"

using namespace std;

template<typename T, int p_to_up>
micro_vector_set<T, p_to_up>::micro_vector_set()
{
	this->a_inner_set = new inner_vector_set<T, p_to_up>();
}

template<typename T, int p_to_up>
micro_vector_set<T, p_to_up>::~micro_vector_set()
{

}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up> micro_vector_set<T, p_to_up>::begin()
{
	return iterator_micro_set<T, p_to_up>(this->a_inner_set);
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up>  micro_vector_set<T, p_to_up>::end()
{
	iterator_micro_set<T, p_to_up> r_iterator_micro_set(this->a_inner_set);

	return r_iterator_micro_set.end();
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up> micro_vector_set<T, p_to_up>::find(T p_element)
{
	iterator_micro_set<T, p_to_up> r_iterator_micro_set(this->a_inner_set);

	while(r_iterator_micro_set != end())
		if(*r_iterator_micro_set == p_element)
			return r_iterator_micro_set;
		else
			r_iterator_micro_set++;

	return r_iterator_micro_set;
}

template<typename T, int p_to_up>
bool micro_vector_set<T, p_to_up>::empty() const
{
    return this->a_inner_set->get_size() == 0;
}

template<typename T, int p_to_up>
int micro_vector_set<T, p_to_up>::size() const
{
    return this->a_inner_set->get_size();
}

template<typename T, int p_to_up>
int micro_vector_set<T, p_to_up>::max_size() const
{
	return -1; //Pas de taille max ?
}
template<typename T, int p_to_up>
void micro_vector_set<T, p_to_up>:: insert(T p_element)
{
	this->a_inner_set = this->a_inner_set->add_element(p_element);
}

template<typename T, int p_to_up>
void micro_vector_set<T, p_to_up>:: erase(T p_element)
{
	this->a_inner_set = this->a_inner_set->remove_element(p_element);
}

template<typename T, int p_to_up>
void micro_vector_set<T, p_to_up>:: clear()
{
	if(a_inner_set != nullptr)
		if(a_inner_set->get_size() != 0)
			delete a_inner_set;

	this->a_inner_set = new inner_vector_set<T, p_to_up>();
}

template<typename T, int p_to_up>
bool micro_vector_set<T, p_to_up>::retain_all(micro_vector_set<T, p_to_up> p_micro_vector_set)
{
	int t_size = size();

	this->a_inner_set = p_micro_vector_set.a_inner_set->retain_all_elements(this->a_inner_set);

	return this->a_inner_set->get_size() != t_size;
}

template<typename T, int p_to_up>
void micro_vector_set<T, p_to_up>::add_all(micro_vector_set<T, p_to_up> p_micro_vector_set)
{
	this->a_inner_set = p_micro_vector_set.a_inner_set->add_all_elements(this->a_inner_set);
}

template<typename T, int p_to_up>
void micro_vector_set<T, p_to_up>::remove_all(micro_vector_set<T, p_to_up> p_micro_vector_set)
{
	this->a_inner_set = p_micro_vector_set.a_inner_set->remove_all_elements(this->a_inner_set);
}

template<typename T, int p_to_up>
micro_vector_set<T, p_to_up>* micro_vector_set<T, p_to_up>::add_all_and_propagate(micro_vector_set<T, p_to_up> p_micro_vector_set)
{
	micro_vector_set<T, p_to_up>* r_micro_vector_set = new micro_vector_set<T, p_to_up>();

	this->a_inner_set = this->a_inner_set->add_all_and_propagate(p_micro_vector_set.a_inner_set, r_micro_vector_set);

	return r_micro_vector_set;
}

template<typename T, int p_to_up>
bool  operator==(const micro_vector_set<T, p_to_up> p_micro_vector_set_a, const micro_vector_set<T, p_to_up> p_micro_vector_set_b)
{

	return true;
}
