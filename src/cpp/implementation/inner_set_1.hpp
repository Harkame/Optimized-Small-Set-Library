#ifndef INNER_SET_1_HPP
#define INNER_SET_1_HPP

#include "inner_set.hpp"

using namespace std;


template<typename T, int p_to_up>
class inner_set_1 : virtual public inner_set<T, p_to_up>
{
                public:
                                struct values
                                {
                                     T element_1;
                                } a_values;

                                inner_set_1<T, p_to_up>();
                                inner_set_1<T, p_to_up>(T);

                                virtual ~inner_set_1<T, p_to_up>();

                                virtual inner_set<T, p_to_up>* add_element(T);
                                virtual inner_set<T, p_to_up>* add_all_elements(inner_set<T, p_to_up>*);

                                virtual bool contains_element(T);
                                virtual bool contains_all_elements(inner_set<T, p_to_up>*);

                                virtual inner_set<T, p_to_up>* copy();

                                virtual T get_element(int);

                                virtual inner_set<T, p_to_up>* remove_element(T);
                                virtual inner_set<T, p_to_up>* remove_all_elements(inner_set<T, p_to_up>*);

                                virtual inner_set<T, p_to_up>* retain_all_elements(inner_set<T, p_to_up>*);

                                virtual inner_set<T, p_to_up>* add_and_propagate(T, micro_set<T, p_to_up>*);
                                virtual inner_set<T, p_to_up>* add_all_and_propagate(inner_set<T, p_to_up>*, micro_set<T, p_to_up>*);
                                virtual inner_set<T, p_to_up>* add_all_and_propagate_reverse(inner_set<T, p_to_up>*, micro_set<T, p_to_up>*);

                                virtual int get_size();
};

#endif
