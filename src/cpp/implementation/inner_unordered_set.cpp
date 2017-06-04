#include "inner_set_0.hpp"
#include "inner_unordered_set.hpp"
#include "iterator_micro_set.hpp"

template<typename T, int p_to_up>
inner_unordered_set<T, p_to_up>::inner_unordered_set() : unordered_set<T>()
{
}

template<typename T, int p_to_up>
inner_unordered_set<T, p_to_up>::inner_unordered_set(inner_set<T, p_to_up>* p_inner_set) : unordered_set<T>()
{
  iterator_micro_set<T, p_to_up> t_iterator(p_inner_set);
  for(t_iterator = t_iterator; t_iterator != t_iterator.end(); t_iterator++)
    this->insert(*t_iterator);
}

template<typename T, int p_to_up>
inner_unordered_set<T, p_to_up>::inner_unordered_set(inner_tree_set<T, p_to_up>* p_inner_tree_set, T p_element) : unordered_set<T>()
{
  this->reserve(20);

  for(auto t_iterator = p_inner_tree_set->begin(); t_iterator != p_inner_tree_set->end(); t_iterator++)
    this->insert(*t_iterator);

  this->insert(p_element);

  delete p_inner_tree_set;
}

template<typename T, int p_to_up>
inner_unordered_set<T, p_to_up>::~inner_unordered_set()
{

}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_unordered_set<T, p_to_up>::add_element(T p_element)
{
    this->insert(p_element);

    return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_unordered_set<T, p_to_up>::add_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  for(auto t_iterator = this->begin(); t_iterator != this->end(); t_iterator++)
  {
       p_inner_set = p_inner_set->add_element(*t_iterator);
  }

    return p_inner_set;
}

template<typename T, int p_to_up>
bool inner_unordered_set<T, p_to_up>::contains_element(T p_element)
{
  auto t_iterator = this->find(p_element);

  return t_iterator != this->end();
}


template<typename T, int p_to_up>
bool inner_unordered_set<T, p_to_up>::contains_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
    for(auto t_iterator = this->begin(); t_iterator != this->end(); t_iterator++)
      if(!p_inner_set->contains_element(*t_iterator))
        return false;

  return true;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>*  inner_unordered_set<T, p_to_up>::copy()
{
	return new inner_unordered_set(this);
}

template<typename T, int p_to_up>
T inner_unordered_set<T, p_to_up>::get_element(int p_index)
{
  auto t_iterator = this->begin();

  std::advance(t_iterator, p_index);

  return *t_iterator;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_unordered_set<T, p_to_up>::remove_element(T p_element)
{
    this->erase(p_element);

    return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_unordered_set<T, p_to_up>::remove_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  for(auto t_iterator = this->begin(); t_iterator != this->end(); t_iterator++)
  {
    p_inner_set->remove_element(*t_iterator);
  }

    return p_inner_set;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_unordered_set<T, p_to_up>::retain_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  inner_set<T, p_to_up>* r_inner_set = inner_set_0<T, p_to_up>::EMPTY;

  for(auto t_iterator = this->begin(); t_iterator != this->end(); t_iterator++)
    if(p_inner_set->contains_element(*t_iterator))
      r_inner_set->add_element(*t_iterator);

  return r_inner_set;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_unordered_set<T, p_to_up>::add_and_propagate(T p_element, micro_set<T, p_to_up>* p_micro_set)
{
  if(!contains_element(p_element))
  {
    p_micro_set->insert(p_element);

    return add_element(p_element);
  }

    return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_unordered_set<T, p_to_up>::add_all_and_propagate(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{
  return p_inner_set->add_all_and_propagate_reverse(this, p_micro_set);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_unordered_set<T, p_to_up>::add_all_and_propagate_reverse(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{
  for(auto t_iterator = this->begin(); t_iterator != this->end(); t_iterator++)
    p_inner_set = p_inner_set->add_and_propagate(*t_iterator, p_micro_set);

  return p_inner_set;
}

template<typename T, int p_to_up>
int inner_unordered_set<T, p_to_up>::get_size()
{
    return this->size();
}
