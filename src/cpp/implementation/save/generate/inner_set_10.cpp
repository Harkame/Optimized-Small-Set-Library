#include "inner_set_10.hpp"

template<typename T, int p_to_up>
inner_set_10<T, p_to_up>::inner_set_10()
{

}

template<typename T, int p_to_up>
inner_set_10<T, p_to_up>::inner_set_10(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5, T p_element_6, T p_element_7, T p_element_8, T p_element_9, T p_element_10)
{
            a_values.element_1 = p_element_1;
            a_values.element_2 = p_element_2;
            a_values.element_3 = p_element_3;
            a_values.element_4 = p_element_4;
            a_values.element_5 = p_element_5;
            a_values.element_6 = p_element_6;
            a_values.element_7 = p_element_7;
            a_values.element_8 = p_element_8;
            a_values.element_9 = p_element_9;
            a_values.element_10 = p_element_10;
    }

template<typename T, int p_to_up>
inner_set_10<T, p_to_up>::inner_set_10(inner_set_9<T, p_to_up>* p_inner_set, T p_element)
{
            a_values.element_1 = p_inner_set->a_values.element_1;            a_values.element_2 = p_inner_set->a_values.element_2;            a_values.element_3 = p_inner_set->a_values.element_3;            a_values.element_4 = p_inner_set->a_values.element_4;            a_values.element_5 = p_inner_set->a_values.element_5;            a_values.element_6 = p_inner_set->a_values.element_6;            a_values.element_7 = p_inner_set->a_values.element_7;            a_values.element_8 = p_inner_set->a_values.element_8;            a_values.element_9 = p_inner_set->a_values.element_9;                    a_values.element_10 = p_element;
    
	delete p_inner_set;
}

template<typename T, int p_to_up>
inner_set_10<T, p_to_up>::~inner_set_10()
{

}

template<typename T, int p_to_up>
inner_set<T, p_to_up>*  inner_set_10<T, p_to_up>::copy()
{
	return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_10<T, p_to_up>::add_element(T p_element)
{
	if(!contains_element(p_element))
		if(this->a_to_up == 10)
			return new inner_array_set<T, p_to_up>(this, p_element);
		else
			return new inner_set_11<T, p_to_up>(this, p_element);
	else
		return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_10<T, p_to_up>::add_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  return p_inner_set->add_element(a_values.element_1)->add_element(a_values.element_2)->add_element(a_values.element_3)->add_element(a_values.element_4)->add_element(a_values.element_5)->add_element(a_values.element_6)->add_element(a_values.element_7)->add_element(a_values.element_8)->add_element(a_values.element_9)->add_element(a_values.element_10);
}

template<typename T, int p_to_up>
bool inner_set_10<T, p_to_up>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element ||  a_values.element_2 == p_element ||  a_values.element_3 == p_element ||  a_values.element_4 == p_element ||  a_values.element_5 == p_element ||  a_values.element_6 == p_element ||  a_values.element_7 == p_element ||  a_values.element_8 == p_element ||  a_values.element_9 == p_element ||  a_values.element_10 == p_element;
}

template<typename T, int p_to_up>
bool inner_set_10<T, p_to_up>::contains_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
   return  p_inner_set->contains_element(a_values.element_1)  &&   p_inner_set->contains_element(a_values.element_2)  &&   p_inner_set->contains_element(a_values.element_3)  &&   p_inner_set->contains_element(a_values.element_4)  &&   p_inner_set->contains_element(a_values.element_5)  &&   p_inner_set->contains_element(a_values.element_6)  &&   p_inner_set->contains_element(a_values.element_7)  &&   p_inner_set->contains_element(a_values.element_8)  &&   p_inner_set->contains_element(a_values.element_9)  &&   p_inner_set->contains_element(a_values.element_10) ;
}

template<typename T, int p_to_up>
T inner_set_10<T, p_to_up>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_10<T, p_to_up>::remove_element(T p_element)
{
                if(a_values.element_1 == p_element)
                {
        	delete this;
        	return new inner_set_9<T, p_to_up>(a_values.element_2a_values.element_3a_values.element_4a_values.element_5a_values.element_6a_values.element_7a_values.element_8a_values.element_9a_values.element_10);
    	}
         else                 if(a_values.element_2 == p_element)
                {
        	delete this;
        	return new inner_set_9<T, p_to_up>(a_values.element_1a_values.element_3a_values.element_4a_values.element_5a_values.element_6a_values.element_7a_values.element_8a_values.element_9a_values.element_10);
    	}
         else                 if(a_values.element_3 == p_element)
                {
        	delete this;
        	return new inner_set_9<T, p_to_up>(a_values.element_1a_values.element_2a_values.element_4a_values.element_5a_values.element_6a_values.element_7a_values.element_8a_values.element_9a_values.element_10);
    	}
         else                 if(a_values.element_4 == p_element)
                {
        	delete this;
        	return new inner_set_9<T, p_to_up>(a_values.element_1a_values.element_2a_values.element_3a_values.element_5a_values.element_6a_values.element_7a_values.element_8a_values.element_9a_values.element_10);
    	}
         else                 if(a_values.element_5 == p_element)
                {
        	delete this;
        	return new inner_set_9<T, p_to_up>(a_values.element_1a_values.element_2a_values.element_3a_values.element_4a_values.element_6a_values.element_7a_values.element_8a_values.element_9a_values.element_10);
    	}
         else                 if(a_values.element_6 == p_element)
                {
        	delete this;
        	return new inner_set_9<T, p_to_up>(a_values.element_1a_values.element_2a_values.element_3a_values.element_4a_values.element_5a_values.element_7a_values.element_8a_values.element_9a_values.element_10);
    	}
         else                 if(a_values.element_7 == p_element)
                {
        	delete this;
        	return new inner_set_9<T, p_to_up>(a_values.element_1a_values.element_2a_values.element_3a_values.element_4a_values.element_5a_values.element_6a_values.element_8a_values.element_9a_values.element_10);
    	}
         else                 if(a_values.element_8 == p_element)
                {
        	delete this;
        	return new inner_set_9<T, p_to_up>(a_values.element_1a_values.element_2a_values.element_3a_values.element_4a_values.element_5a_values.element_6a_values.element_7a_values.element_9a_values.element_10);
    	}
         else                 if(a_values.element_9 == p_element)
                {
        	delete this;
        	return new inner_set_9<T, p_to_up>(a_values.element_1a_values.element_2a_values.element_3a_values.element_4a_values.element_5a_values.element_6a_values.element_7a_values.element_8a_values.element_10);
    	}
         else                 if(a_values.element_10 == p_element)
                {
        	delete this;
        	return new inner_set_9<T, p_to_up>(a_values.element_1a_values.element_2a_values.element_3a_values.element_4a_values.element_5a_values.element_6a_values.element_7a_values.element_8a_values.element_9);
    	}
                        else
            return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_10<T, p_to_up>::remove_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  return p_inner_set->remove_element(a_values.element_1)->remove_element(a_values.element_2)->remove_element(a_values.element_3)->remove_element(a_values.element_4)->remove_element(a_values.element_5)->remove_element(a_values.element_6)->remove_element(a_values.element_7)->remove_element(a_values.element_8)->remove_element(a_values.element_9)->remove_element(a_values.element_10);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_10<T, p_to_up>::retain_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  inner_set<T, p_to_up>* r_inner_set = inner_set_0<T, p_to_up>::EMPTY;

		if(p_inner_set->contains_element(a_values.element_1))
		 r_inner_set = r_inner_set->add_element(a_values.element_1);
	
	 	if(p_inner_set->contains_element(a_values.element_2))
		 r_inner_set = r_inner_set->add_element(a_values.element_2);
	
	 	if(p_inner_set->contains_element(a_values.element_3))
		 r_inner_set = r_inner_set->add_element(a_values.element_3);
	
	 	if(p_inner_set->contains_element(a_values.element_4))
		 r_inner_set = r_inner_set->add_element(a_values.element_4);
	
	 	if(p_inner_set->contains_element(a_values.element_5))
		 r_inner_set = r_inner_set->add_element(a_values.element_5);
	
	 	if(p_inner_set->contains_element(a_values.element_6))
		 r_inner_set = r_inner_set->add_element(a_values.element_6);
	
	 	if(p_inner_set->contains_element(a_values.element_7))
		 r_inner_set = r_inner_set->add_element(a_values.element_7);
	
	 	if(p_inner_set->contains_element(a_values.element_8))
		 r_inner_set = r_inner_set->add_element(a_values.element_8);
	
	 	if(p_inner_set->contains_element(a_values.element_9))
		 r_inner_set = r_inner_set->add_element(a_values.element_9);
	
	 	if(p_inner_set->contains_element(a_values.element_10))
		 r_inner_set = r_inner_set->add_element(a_values.element_10);
	
	 
    if(this->get_size() != 0)
      delete this;

  return r_inner_set;
}


template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_10<T, p_to_up>::add_and_propagate(T p_element, micro_set<T, p_to_up>* p_micro_set)
{
	if( a_values.element_1 == p_element  ||   a_values.element_2 == p_element  ||   a_values.element_3 == p_element  ||   a_values.element_4 == p_element  ||   a_values.element_5 == p_element  ||   a_values.element_6 == p_element  ||   a_values.element_7 == p_element  ||   a_values.element_8 == p_element  ||   a_values.element_9 == p_element  ||   a_values.element_10 == p_element )
		return this;
	else
  	{
  		p_micro_set->insert(p_element);

		return new inner_set_11<T, p_to_up>(this, p_element);
	}
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_10<T, p_to_up>::add_all_and_propagate(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{
  return p_inner_set->add_all_and_propagate_reverse(this, p_micro_set);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_10<T, p_to_up>::add_all_and_propagate_reverse(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{
	return p_inner_set->add_and_propagate(a_values.element_1, p_micro_set)->add_and_propagate(a_values.element_2, p_micro_set)->add_and_propagate(a_values.element_3, p_micro_set)->add_and_propagate(a_values.element_4, p_micro_set)->add_and_propagate(a_values.element_5, p_micro_set)->add_and_propagate(a_values.element_6, p_micro_set)->add_and_propagate(a_values.element_7, p_micro_set)->add_and_propagate(a_values.element_8, p_micro_set)->add_and_propagate(a_values.element_9, p_micro_set)->add_and_propagate(a_values.element_10, p_micro_set);
}

template<typename T, int p_to_up>
int inner_set_2<T, p_to_up>::get_size()
{
    return 10;
}
