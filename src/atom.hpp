#pragma once

#include "atomic_formula.hpp"

class atom : public atomic_formula
{
public:
  atom(unsigned p);
  virtual std::ostream& print(std::ostream &out) const;
  virtual bool eval(const valuation &val) const;
  virtual void get_atoms(atom_set &a_set) const;
  virtual bool equal(const formula &f) const;

private:
  unsigned m_p;
};
