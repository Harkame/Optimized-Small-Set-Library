#include "inner_set_1.hpp"

template<typename T, int p_to_up>
inner_set_1<T, p_to_up>::inner_set_1()
{

}

template<typename T, int p_to_up>
inner_set_1<T, p_to_up>::inner_set_1(T p_element_1)
{
            a_values.element_1 = p_element_1;
    }

template<typename T, int p_to_up>
inner_set_1<T, p_to_up>::inner_set_1(inner_set_0<T, p_to_up>* p_inner_set, T p_element)
{
                    a_values.element_1 = p_element;
    
	delete p_inner_set;
}

template<typename T, int p_to_up>
inner_set_1<T, p_to_up>::~inner_set_1()
{

}

template<typename T, int p_to_up>
inner_set<T, p_to_up>*  inner_set_1<T, p_to_up>::copy()
{
	return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_1<T, p_to_up>::add_element(T p_element)
{
	if(!contains_element(p_element))
		if(this->a_to_up == 1)
			return new inner_array_set<T, p_to_up>(this, p_element);
		else
			return new inner_set_2<T, p_to_up>(this, p_element);
	else
		return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_1<T, p_to_up>::add_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  return p_inner_set->add_element(a_values.element_1);
}

template<typename T, int p_to_up>
bool inner_set_1<T, p_to_up>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element;
}

template<typename T, int p_to_up>
bool inner_set_1<T, p_to_up>::contains_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
   return  p_inner_set->contains_element(a_values.element_1) ;
}

template<typename T, int p_to_up>
T inner_set_1<T, p_to_up>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_1<T, p_to_up>::remove_element(T p_element)
{
                if(a_values.element_1 == p_element)
                return inner_set_0<T, p_to_up>::EMPTY;
        ;
    	}
                        else
            return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_1<T, p_to_up>::remove_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  return p_inner_set->remove_element(a_values.element_1);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_1<T, p_to_up>::retain_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  inner_set<T, p_to_up>* r_inner_set = inner_set_0<T, p_to_up>::EMPTY;

		if(p_inner_set->contains_element(a_values.element_1))
		 r_inner_set = r_inner_set->add_element(a_values.element_1);
	
	 
    if(this->get_size() != 0)
      delete this;

  return r_inner_set;
}


template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_1<T, p_to_up>::add_and_propagate(T p_element, micro_set<T, p_to_up>* p_micro_set)
{
	if( a_values.element_1 == p_element )
		return this;
	else
  	{
  		p_micro_set->insert(p_element);

		return new inner_set_2<T, p_to_up>(this, p_element);
	}
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_1<T, p_to_up>::add_all_and_propagate(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{
  return p_inner_set->add_all_and_propagate_reverse(this, p_micro_set);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_1<T, p_to_up>::add_all_and_propagate_reverse(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{
	return p_inner_set->add_and_propagate(a_values.element_1, p_micro_set);
}

template<typename T, int p_to_up>
int inner_set_2<T, p_to_up>::get_size()
{
    return 1;
}
