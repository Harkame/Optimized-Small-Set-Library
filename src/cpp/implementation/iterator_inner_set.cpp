iterator_inner_set::iterator_micro_set(inner_set<T>* p_inner_set)
{
  a_index = 0;

  a_inner_set = p_inner_set;
}

iterator_inner_set::~iterator_micro_set()
{

}

iterator_inner_set::T begin()
{
  return a_inner_set->get_element(0);
}

iterator_inner_set::T end()
{
  return a_inner_set->get_element(a_inner_set->get_size());
}

iterator_inner_set::T prev()
{
  return a_inner_set->get_element(a_index--);
}

iterator_inner_set::T next()
{
  return a_inner_set->get_element(a_index++);
}
