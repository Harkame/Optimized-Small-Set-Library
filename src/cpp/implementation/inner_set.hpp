#ifndef INNER_SET_HPP
#define INNER_SET_HPP

#include <cstddef>

using namespace std;

template<typename T, int p_to_up>
class micro_set;

template<typename T, int p_to_up>
class inner_set
{
    public :
      int a_to_up = p_to_up;

      inner_set<T, p_to_up>(){}

      virtual ~inner_set<T, p_to_up>(){}

      virtual inner_set<T, p_to_up>* add_element(T){return nullptr;};
      virtual inner_set<T, p_to_up>* add_element_array(T){return nullptr;};
      virtual inner_set<T, p_to_up>* add_all_elements(inner_set<T, p_to_up>*){return nullptr;};

      virtual bool contains_element(T){return false;};
      virtual bool contains_all_elements(inner_set<T, p_to_up>*){return false;};

      virtual inner_set<T, p_to_up>* copy(){return nullptr;}

      virtual T get_element(int){return (T) NULL;};

      virtual inner_set<T, p_to_up>* remove_element(T){return nullptr;};
      virtual inner_set<T, p_to_up>* remove_all_elements(inner_set<T, p_to_up>*){return nullptr;};

      virtual inner_set<T, p_to_up>* retain_all_elements(inner_set<T, p_to_up>*){return nullptr;};

      virtual inner_set<T, p_to_up>* add_and_propagate(T, micro_set<T, p_to_up>*){return nullptr;}
      virtual inner_set<T, p_to_up>* add_all_and_propagate(inner_set<T, p_to_up>*, micro_set<T, p_to_up>*){return nullptr;}
      virtual inner_set<T, p_to_up>* add_all_and_propagate_reverse(inner_set<T, p_to_up>*, micro_set<T, p_to_up>*){return nullptr;};

      virtual  int get_size(){return 0;};
};


#endif
