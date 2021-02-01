#include "base_formula.hpp"
#include <cassert>

base_formula::base_formula()
{

}

//could use ([[maybe_unused]] var), new cpp17 attribute for unused variables
void base_formula::get_atoms(atom_set &a_set) const
{
  UNUSED(a_set);
}

bool base_formula::equal(const formula &f) const
{
  const base_formula *tmp = f.get();
  return typeid (*this) == typeid (*tmp);
}

base_formula::~base_formula()
{

}
optional_valuation base_formula::is_satisfiable() const
{
  atom_set a_set;
  get_atoms(a_set);
  valuation val{a_set};

  do {
      if (eval(val))
      {
        return val;
      }
    } while (val.next());

  return {};
}

optional_valuation base_formula::is_not_tautology() const
{
  atom_set a_set;
  get_atoms(a_set);
  valuation val{a_set};

  do {
      if (!eval(val))
      {
        return val;
      }
    } while (val.next());

  return {};
}

bool base_formula::is_consequence(const formula &f) const
{
  atom_set a_set;
  get_atoms(a_set);
  f->get_atoms(a_set);
  valuation val{a_set};

  do {
    if (eval(val) && !f->eval(val))
    {
      return false;
    }
  } while (val.next());

  return true;
}
bool base_formula::is_equivalent(const formula &f) const
{
  atom_set a_set;
  get_atoms(a_set);
  f->get_atoms(a_set);
  valuation val{a_set};
  do {
    if (eval(val) != f->eval(val))
    {
      return false;
    }
  } while (val.next());

  return true;
}
void base_formula::print_truth_table(std::ostream &out) const
{
  atom_set a_set;
  get_atoms(a_set);
  valuation val{a_set};
  out << std::noboolalpha;
  do {
    out << val << " | " << eval(val) << '\n';
  } while (val.next());
}

bool operator==(const formula &left, const formula &right)
{
    return left->equal(right);
}
bool operator!=(const formula &left, const formula &right)
{
  return !(left == right);
}
std::ostream& operator<<(std::ostream &out, const formula &f)
{
  return f->print(out);
}
