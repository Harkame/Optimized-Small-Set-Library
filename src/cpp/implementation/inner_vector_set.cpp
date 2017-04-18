#include "inner_vector_set.hpp"
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
    if(std::find(a_values->begin(), a_values->end(), p_element) == a_values->end())
      a_values->push_back(p_element);

    return this;
}

template<typename T>
inner_set<T>* inner_vector_set<T>::add_all_elements(inner_set<T>* p_inner_set)
{
  /*
  set<T>::iterator t_iterator = a_values.begin() ;

  for (t_iterator ; t_iterator != a_values.end() ; t_iterator++)
    p_inner_set->add_element(t_iterator);

  return nullptr; //TODO
  */

  return p_inner_set;
}

template<typename T>
bool inner_vector_set<T>::contains_element(T p_element)
{
  //return (a_values.find(p_element) == p_element);
  return p_element == p_element;
}

template<typename T>
bool inner_vector_set<T>::contains_all_elements(inner_set<T>* p_inner_set)
{
  p_inner_set = p_inner_set;

  return false;
}

template<typename T>
T inner_vector_set<T>::get_element(int p_index)
{
  return a_values->at(p_index);
}

template<typename T>
inner_set<T>* inner_vector_set<T>::remove_element(T p_element)
{
  p_element = p_element;
  /*
            if(a_values.element_1 == p_element)
            return new inner_set_10<T>( a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_2 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_3 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_4 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_5 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_6 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_7 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_8 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_9 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_10);
         else             if(a_values.element_10 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9);
                else
                */
        return this;
}

template<typename T>
inner_set<T>* inner_vector_set<T>::remove_all_elements(inner_set<T>* p_inner_set)
{
  return p_inner_set;
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
