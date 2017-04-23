#ifndef MICRO_VECTOR_SET
#define MICRO_VECTOR_SET

#include <map>
#include <set>

#include "inner_set.hpp"
#include "inner_set_0.hpp"

#include "inner_vector_set.hpp"

using namespace std;

template<typename T>
class micro_vector_set : public set<T>
{
    private :
        inner_set<T>* a_inner_set;

    public :
        micro_vector_set();

        virtual ~micro_vector_set();

        virtual iterator_inner_set<T> begin();

        virtual iterator_inner_set<T> end();

//        virtual iterator_inner_set<T>* find(T);

        virtual bool empty() const;

        virtual int size() const;

        virtual int max_size() const;

        virtual void insert(T);

        virtual void erase(T);

        virtual void clear();

        virtual bool retain_all(micro_vector_set<T>);
  };

#endif
