#include "inner_tree_set.hpp"

template<typename T>
inner_tree_set<T>::inner_tree_set()
{
  a_values = new set<T>();
}

template<typename T>
inner_tree_set<T>::inner_tree_set(inner_array_set<T>* p_inner_set, T p_element)
{
  a_values = new set<T>();

  a_values->insert(p_inner_set->a_values[0]);
  a_values->insert(p_inner_set->a_values[1]);
  a_values->insert(p_inner_set->a_values[2]);
  a_values->insert(p_inner_set->a_values[3]);
  a_values->insert(p_inner_set->a_values[4]);
  a_values->insert(p_inner_set->a_values[5]);
  a_values->insert(p_inner_set->a_values[6]);
  a_values->insert(p_inner_set->a_values[7]);
  a_values->insert(p_inner_set->a_values[8]);
  a_values->insert(p_inner_set->a_values[9]);
  a_values->insert(p_inner_set->a_values[10]);
  a_values->insert(p_inner_set->a_values[11]);
  a_values->insert(p_inner_set->a_values[12]);
  a_values->insert(p_inner_set->a_values[13]);
  a_values->insert(p_inner_set->a_values[14]);
  a_values->insert(p_inner_set->a_values[15]);
  a_values->insert(p_inner_set->a_values[16]);
  a_values->insert(p_inner_set->a_values[17]);
  a_values->insert(p_inner_set->a_values[18]);
  a_values->insert(p_inner_set->a_values[19]);

  a_values->insert(p_element);

  delete p_inner_set;
}

template<typename T>
inner_tree_set<T>::~inner_tree_set()
{

}

template<typename T>
inner_set<T>* inner_tree_set<T>::add_element(T p_element)
{
    a_values->insert(p_element);

    return this;
}

template<typename T>
inner_set<T>* inner_tree_set<T>::add_all_elements(inner_set<T>* p_inner_set)
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
bool inner_tree_set<T>::contains_element(T p_element)
{
  //return (a_values.find(p_element) == p_element);
  return p_element == p_element;
}

template<typename T>
bool inner_tree_set<T>::contains_all_elements(inner_set<T>* p_inner_set)
{
  p_inner_set = p_inner_set;

  return false;
}

template<typename T>
T inner_tree_set<T>::get_element(int p_index)
{
    //return a_values->at(p_index);
    return (T) p_index;
}

template<typename T>
inner_set<T>* inner_tree_set<T>::remove_element(T p_element)
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
inner_set<T>* inner_tree_set<T>::remove_all_elements(inner_set<T>* p_inner_set)
{
  return p_inner_set;
}

template<typename T>
inner_set<T>* inner_tree_set<T>::retain_all_elements(inner_set<T>* p_inner_set)
{
  return p_inner_set;
}

template<typename T>
int inner_tree_set<T>::get_size()
{
    return a_values->size();
}
