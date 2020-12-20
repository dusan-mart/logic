#include "unary_connective.hpp"



unary_connective::unary_connective(const formula &f)
  :base_formula(), f(f)
{

}

unsigned unary_connective::complexity() const
{
  return 1 + f->complexity();
}
void unary_connective::get_atoms(atom_set &a_set) const
{
  f->get_atoms(a_set);
}
bool unary_connective::equal(const formula &f) const
{
  if(base_formula::equal(f))
  {
    const unary_connective *tmp = static_cast<const unary_connective *>(f.get());
    return tmp->f == f;
  }
  return false;
}
formula unary_connective::operand() const
{
  return f;
}
