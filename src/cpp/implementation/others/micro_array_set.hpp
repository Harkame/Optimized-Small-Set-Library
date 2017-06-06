#ifndef micro_array_set_HPP
#define micro_array_set_HPP

#include "../inner_set.hpp"
#include "../inner_set_0.hpp"

#include "../iterator_micro_set.hpp"
#include "../micro_set.hpp"

using namespace std;

template<typename T, int p_to_up>
class micro_array_set : micro_set<T, p_to_up>
{
    private:
      inner_set<T, p_to_up>* a_inner_set;


  public:
      micro_array_set();

      virtual ~micro_array_set();

      /* Iterators */
      virtual iterator_micro_set<T, p_to_up> begin() const;

      virtual iterator_micro_set<T, p_to_up> end() const;

      virtual iterator_micro_set<T, p_to_up> find(T) const;

      /* Capacity */
      virtual bool empty() const;

      virtual int size() const;

      /* Modifiers */
      virtual void insert(T);

      virtual void insert_all(micro_array_set<T, p_to_up>);

      virtual void erase(T);

      virtual void erase_all(micro_array_set<T, p_to_up>);

      virtual void retain_all(micro_array_set<T, p_to_up>);

      virtual void clear();

      /* Custom */
      virtual micro_array_set<T, p_to_up>* add_all_and_propagate(micro_array_set<T, p_to_up>);

      friend class inner_set_0<T, p_to_up>;
};

#endif
