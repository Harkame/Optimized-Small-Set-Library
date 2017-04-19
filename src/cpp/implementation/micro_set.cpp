#include "micro_set.hpp"
#include "iterator_inner_set.hpp"


using namespace std;

template<typename T>
micro_set<T>::micro_set()
{
	a_inner_set = new inner_set_0<T>();
}

template<typename T>
micro_set<T>::~micro_set()
{

}


template<typename T>
iterator_inner_set<T>* micro_set<T>::begin()
{
	return new iterator_inner_set<T>(a_inner_set);
}

template<typename T>
iterator_inner_set<T>* micro_set<T>::end()
{
	iterator_inner_set<T>* r_iterator_inner_set = new iterator_inner_set<T>(a_inner_set);

	r_iterator_inner_set->set_end();

	return r_iterator_inner_set;
}

template<typename T>
iterator_inner_set<T>* micro_set<T>::find(T p_element)
{
	iterator_inner_set<T>* r_iterator_inner_set = new iterator_inner_set<T>(a_inner_set);

	while(r_iterator_inner_set->next() != p_element);

	return r_iterator_inner_set;

}

template<typename T>
bool micro_set<T>::empty() const
{
    return a_inner_set->get_size() == 0;
}

template<typename T>
int micro_set<T>::size() const
{
    return a_inner_set->get_size();
}

template<typename T>
int micro_set<T>::max_size() const
{
	return -1; //Pas de taille max ?
}
template<typename T>
void micro_set<T>:: insert(T p_element)
{
	a_inner_set = a_inner_set->add_element(p_element);
}

template<typename T>
void micro_set<T>:: erase(T p_element)
{
	a_inner_set = a_inner_set->remove_element(p_element);
}

template<typename T>
void micro_set<T>:: clear()
{
	delete a_inner_set;

	a_inner_set = new inner_set_0<T>();
}
