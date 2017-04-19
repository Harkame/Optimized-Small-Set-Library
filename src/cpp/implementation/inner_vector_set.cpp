#include "inner_vector_set.hpp"

#include <vector>
using namespace std;

template<typename T>
inner_vector_set<T>::inner_vector_set()
{
  a_values = new vector<T>();
}

template<typename T>
inner_vector_set<T>::~inner_vector_set()
{

}

template<typename T>
inner_set<T>* inner_vector_set<T>::add_element(T p_element)
{
    if(!contains_element(p_element))
    {
      cout << p_element << endl;
      a_values->push_back(p_element);
    }

    return this;
}

template<typename T>
inner_set<T>* inner_vector_set<T>::add_all_elements(inner_set<T>* p_inner_set)
{
  for(auto t_iterator = a_values->begin(); t_iterator != a_values->end(); t_iterator++)
    p_inner_set->add_element(*t_iterator);

    return p_inner_set;
}

template<typename T>
bool inner_vector_set<T>::contains_element(T p_element)
{
  return std::find(a_values->begin(), a_values->end(), p_element) == a_values->end();
}

template<typename T>
bool inner_vector_set<T>::contains_all_elements(inner_set<T>* p_inner_set)
{
  for(auto t_iterator = a_values->begin(); t_iterator != a_values->end(); t_iterator++)
      if(!p_inner_set->contains_element(*t_iterator))
        return false;

  return true;
}

template<typename T>
T inner_vector_set<T>::get_element(int p_index)
{
  return a_values->at(p_index);
}

template<typename T>
inner_set<T>* inner_vector_set<T>::remove_element(T p_element)
{
  if(!contains_element(p_element))
    return this;

  auto t_iterator = a_values->begin();

  std::advance(t_iterator, p_element);

  a_values->erase(t_iterator);

  return this;
}

template<typename T>
inner_set<T>* inner_vector_set<T>::remove_all_elements(inner_set<T>* p_inner_set)
{
  a_values->clear();
}

template<typename T>
inner_set<T>* inner_vector_set<T>::retain_all_element(inner_set<T>* p_inner_set)
{
  return p_inner_set;
}

template<typename T>
int inner_vector_set<T>::get_size()
{
    return a_values->size();
}
