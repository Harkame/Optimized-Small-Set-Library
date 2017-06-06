#ifndef MICRO_VECTOR_SET_HPP
#define MICRO_VECTOR_SET_HPP

#include "../inner_set.hpp"
#include "../inner_set_0.hpp"

#include "../iterator_micro_set.hpp"

using namespace std;

template<typename T, int p_to_up>
class micro_vector_set : virtual public micro_set<T, p_to_up>
{
  private:
    inner_set<T, p_to_up>* a_inner_set;

    public :
      micro_vector_set();

      virtual ~micro_vector_set();

      virtual iterator_micro_set<T, p_to_up> begin();

      virtual iterator_micro_set<T, p_to_up> end();

      virtual iterator_micro_set<T, p_to_up> find(T);

      virtual bool empty() const;

      virtual int size() const;

      virtual int max_size() const;

      virtual void insert(T);

      virtual void erase(T);

      virtual void clear();

      virtual bool retain_all(micro_vector_set<T, p_to_up>);

      virtual void add_all(micro_vector_set<T, p_to_up>);

      virtual void remove_all(micro_vector_set<T, p_to_up>);

      virtual micro_vector_set<T, p_to_up>* add_all_and_propagate(micro_vector_set<T, p_to_up>);
  };

#endif
