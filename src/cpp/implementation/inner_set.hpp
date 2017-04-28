#ifndef INNER_SET_HPP
#define INNER_SET_HPP

using namespace std;

template<typename T>

class micro_set;

template<typename T>
class inner_set
{
    public :
      struct values
      {
      } a_values;

      inner_set<T>(){}

      virtual ~inner_set<T>(){}

      virtual inner_set<T>* add_element(T){return nullptr;};
      virtual inner_set<T>* add_all_elements(inner_set<T>*){return nullptr;};

      virtual bool contains_element(T){return false;};
      virtual bool contains_all_elements(inner_set<T>*){return false;};

      virtual T get_element(int){return (T) NULL;};

      virtual inner_set<T>* remove_element(T){return nullptr;};
      virtual inner_set<T>* remove_all_elements(inner_set<T>*){return nullptr;};

      virtual inner_set<T>* retain_all_elements(inner_set<T>*){return nullptr;};

      virtual inner_set<T>* add_and_propagate(T, micro_set<T>*){return nullptr;}
      virtual inner_set<T>* add_all_and_propagate(inner_set<T>*, micro_set<T>*){return nullptr;}
      virtual inner_set<T>* add_all_and_propagate_reverse(inner_set<T>*, micro_set<T>*){return nullptr;};

      virtual  int get_size(){return 0;};
};


#endif
