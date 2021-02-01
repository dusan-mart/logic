#include "atom.hpp"

atom::atom(unsigned p)
  :atomic_formula(), m_p(p)
{

}

std::ostream& atom::print(std::ostream &out) const
{
  return out << "p_" << m_p;
}

bool atom::eval(const valuation &val) const
{
  return val.value(m_p);
}

void atom::get_atoms(atom_set &a_set) const
{
  a_set.insert(m_p);
}

bool atom::equal(const formula &f) const
{
  if(base_formula::equal(f))
  {
    const atom *pf = static_cast<const atom*>(f.get());
    return pf->m_p == m_p;
  }
  return false;
}
