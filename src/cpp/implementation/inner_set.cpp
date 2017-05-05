#include "inner_set.hpp"
#include "iterator_micro_set.hpp"

template<typename T>
bool operator==(const inner_set<T> p_inner_set_a, const inner_set<T> p_inner_set_b)
{
	if(p_inner_set_a.get_size() != p_inner_set_b.get_size())
		return false;

	iterator_micro_set<T> t_iterator_micro_set_a(p_inner_set_a);
	iterator_micro_set<T> t_iterator_micro_set_b(p_inner_set_b);

	for(int t_index; t_index < p_inner_set_a.get_size(); t_index++)
		if(*t_iterator_micro_set_a++ != *t_iterator_micro_set_b++)
			return false;

	return true;
}

template<typename T>
bool operator!=(const inner_set<T> p_inner_set_a, const inner_set<T> p_inner_set_b)
{
	if(p_inner_set_a.get_size() != p_inner_set_b.get_size())
		return true;

	iterator_micro_set<T> t_iterator_micro_set_a(p_inner_set_a);
	iterator_micro_set<T> t_iterator_micro_set_b(p_inner_set_b);

	for(int t_index; t_index < p_inner_set_a.get_size(); t_index++)
		if(*t_iterator_micro_set_a++ != *t_iterator_micro_set_b++)
			return true;

	return false;
}
