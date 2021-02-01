#include "binary_connective.hpp"


binary_connective::binary_connective(const formula &f1, const formula &f2)
  : base_formula(), f1(f1), f2(f2)
{

}

std::ostream& binary_connective::print(std::ostream &out) const
{
  out << '(';
  f1->print(out);
  out << symbol();
  f2->print(out);
  out << ")";

  return out;
}
unsigned binary_connective::complexity() const
{
  return 1 + f1->complexity() + f2->complexity();
}
void binary_connective::get_atoms(atom_set &a_set) const
{
  f1->get_atoms(a_set);
  f2->get_atoms(a_set);
  return;
}
bool binary_connective::equal(const formula &f) const
{
  if(base_formula::equal(f))
  {
    const binary_connective *tmp = static_cast<const binary_connective*>(f.get());
    return f1 == tmp->f1 && f2 == tmp->f2;
  }
  return false;
}
std::pair<formula, formula> binary_connective::operands() const
{
  return {f1, f2};
}
