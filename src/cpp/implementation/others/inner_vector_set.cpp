#include "inner_vector_set.hpp"


#include "../inner_set_0.hpp"

using namespace std;

template<typename T, int p_to_up>
inner_vector_set<T, p_to_up>::inner_vector_set() : vector<T>()
{
}

template<typename T, int p_to_up>
inner_vector_set<T, p_to_up>::inner_vector_set(inner_set<T, p_to_up>* p_inner_set) : vector<T>()
{
  iterator_micro_set<T, p_to_up> t_iterator(p_inner_set);

  for(t_iterator = t_iterator; t_iterator != t_iterator.end(); t_iterator++)
    this->push_back(*t_iterator);
}

template<typename T, int p_to_up>
inner_vector_set<T, p_to_up>::~inner_vector_set()
{

}

template<typename T, int p_to_up>
inner_set<T, p_to_up>*  inner_vector_set<T, p_to_up>::copy()
{
	return new inner_vector_set<T, p_to_up>(this);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_vector_set<T, p_to_up>::add_element(T p_element)
{
    if(!contains_element(p_element))
    {
      this->push_back(p_element);
    }

    return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_vector_set<T, p_to_up>::add_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  for(auto t_iterator = this->begin(); t_iterator != this->end(); t_iterator++)
  {
  p_inner_set->add_element(*t_iterator);
  }

    return p_inner_set;
}

template<typename T, int p_to_up>
bool inner_vector_set<T, p_to_up>::contains_element(T p_element)
{
  return find(this->begin(), this->end(), p_element) != this->end();
}

template<typename T, int p_to_up>
bool inner_vector_set<T, p_to_up>::contains_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  for(auto t_iterator = this->begin(); t_iterator != this->end(); t_iterator++)
  {
      if(!p_inner_set->contains_element(*t_iterator))
        return false;
  }

  return false;
}

template<typename T, int p_to_up>
T inner_vector_set<T, p_to_up>::get_element(int p_index)
{
  return this->at(p_index);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_vector_set<T, p_to_up>::remove_element(T p_element)
{
  auto t_iterator = find(this->begin(), this->end(), p_element);

  if(t_iterator == this->end())
    return this;

  this->erase(t_iterator);

  return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_vector_set<T, p_to_up>::remove_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  for(auto t_iterator = this->begin(); t_iterator != this->end(); t_iterator++)
  {
    p_inner_set->remove_element(*t_iterator);
  }

    return p_inner_set;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_vector_set<T, p_to_up>::retain_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  inner_set<T, p_to_up>* r_inner_set = inner_set_0<T, p_to_up>::EMPTY;

  for(auto t_iterator = this->begin(); t_iterator != this->end(); t_iterator++)
    if(p_inner_set->contains_element(*t_iterator))
      r_inner_set->add_element(*t_iterator);

  return r_inner_set;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_vector_set<T, p_to_up>::add_and_propagate(T p_element, micro_set<T, p_to_up>* p_micro_set)
{
  if(!contains_element(p_element))
  {
    p_micro_set->insert(p_element);

    return add_element(p_element);
  }

    return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_vector_set<T, p_to_up>::add_all_and_propagate(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{
  return p_inner_set->add_all_and_propagate_reverse(this, p_micro_set);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_vector_set<T, p_to_up>::add_all_and_propagate_reverse(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{
  for(auto t_iterator = this->begin(); t_iterator != this->end(); t_iterator++)
    p_inner_set = p_inner_set->add_and_propagate(*t_iterator, p_micro_set);

  return p_inner_set;
}

template<typename T, int p_to_up>
int inner_vector_set<T, p_to_up>::get_size()
{
    return this->size();
}
