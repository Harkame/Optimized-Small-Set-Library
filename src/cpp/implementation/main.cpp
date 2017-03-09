#include "inner_set_0.hpp"
#include "inner_set_1.hpp"
#include "inner_set_2.hpp"

template<typename T>
inner_set_0<T>::inner_set_0()
{

}

template<typename T>
inner_set_0<T>::~inner_set_0()
{

}

template<typename T>
inner_set<T>* inner_set_0<T>::add_element(T p_element)
{
	inner_set_1<T>* r_i1 = new inner_set_1<T>(p_element);

	return r_i1;

	//return nullptr;
}

template<typename T>
inner_set<T>* inner_set_0<T>::add_elements(T* p_elements)
{
	return nullptr;
}

template<typename T>
bool inner_set_0<T>::contains_element(T p_element)
{
    return false;
}

template<typename T>
bool inner_set_0<T>::contains_all_elements(T* p_elements)
{
    return false;
}

template<typename T>
T inner_set_0<T>::get_element(int p_index)
{
    return (T) NULL;
}

template<typename T>
inner_set<T>* inner_set_0<T>::remove_element(T p_element)
{
    return this;
}

template<typename T>
inner_set<T>* inner_set_0<T>::retain_all_element(T* p_elements)
{
    return nullptr;
}

template<typename T>
int inner_set_0<T>::get_size()
{
    return 0;
}

template<typename T>
void inner_set_0<T>::print()
{
    cout << "{}" << endl;
}

template<typename T>
inner_set_1<T>::inner_set_1()
{

}

template<typename T>
inner_set_1<T>::inner_set_1(T p_element)
{
	a_values.element_1 = p_element;
}

template<typename T>
inner_set_1<T>::~inner_set_1()
{

}

template<typename T>
inner_set<T>* inner_set_1<T>::add_element(T p_element)
{
    return new inner_set_2<T>(a_values.element_1, p_element);
}

template<typename T>
inner_set<T>* inner_set_1<T>::add_elements(T* p_elements)
{
	return nullptr;
}

template<typename T>
bool inner_set_1<T>::contains_element(T p_element)
{
    return false;
}

template<typename T>
bool inner_set_1<T>::contains_all_elements(T* p_elements)
{
    return false;
}

template<typename T>
T inner_set_1<T>::get_element(int p_index)
{
		return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_1<T>::remove_element(T p_element)
{
    if(a_values.element_1 == p_element)
      return new inner_set_1<int>(a_values.element_2);
    else if(a_values.element_2 == p_element))
      return new inner_set_1<int>(a_values.element_1);
    else
      return this;
}

template<typename T>
inner_set<T>* inner_set_1<T>::retain_all_element(T* p_elements)
{
	//TODO
	return nullptr;
}

template<typename T>
int inner_set_1<T>::get_size()
{
    return 0;
}

template<typename T>
void inner_set_1<T>::print()
{
    cout << "{" << a_values.element_1 << "}" << endl;
}


template<typename T>
inner_set_2<T>::inner_set_2()
{

}

template<typename T>
inner_set_2<T>::inner_set_2(T p_element_1, T p_element_2)
{
  a_values.element_1 = p_element_1;
  a_values.element_2 = p_element_2;
}

template<typename T>
inner_set_2<T>::~inner_set_2()
{

}

template<typename T>
inner_set<T>* inner_set_2<T>::add_element(T p_element)
{
    return new inner_set_1<T>(p_element);
}

template<typename T>
inner_set<T>* inner_set_2<T>::add_elements(T* p_elements)
{
	return nullptr;
}

template<typename T>
bool inner_set_2<T>::contains_element(T p_element)
{
    return false;
}

template<typename T>
bool inner_set_2<T>::contains_all_elements(T* p_elements)
{
    return false;
}

template<typename T>
T inner_set_2<T>::get_element(int p_index)
{
	return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_2<T>::remove_element(T p_element)
{
    if(a_values.element_1 == p_element)
    	return new inner_set_1<T>(a_values.element_1);
    else if(a_values.element_2 == p_element)
    	return new inner_set_1<T>(a_values.element_2);
    else
    	return this;
}

template<typename T>
inner_set<T>* inner_set_2<T>::retain_all_element(T* p_elements)
{
    return this;
}

template<typename T>
int inner_set_2<T>::get_size()
{
    return 0;
}

template<typename T>
void inner_set_2<T>::print()
{
    cout << "{" << a_values.element_1 << ", " << a_values.element_2 << "}" << endl;
}

int main()
{
	inner_set<int>* i0 = new inner_set_0<int>();
  inner_set<int>* i1;
  inner_set<int>* i2;

  i0->print();

  i1 = i0->add_element(12);
  i1->print();

  i2 = i1->add_element(42);
  i2->print();

  i1 = i2->remove_element(12);
  i1->print();

  i0 = i1->remove_element(42);
  i0->print();

	return 0;
}
