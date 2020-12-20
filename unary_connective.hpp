#pragma once

#include "base_formula.hpp"

class unary_connective : public base_formula{
public:
  unary_connective(const formula &f);
  unsigned complexity() const;
  void get_atoms(atom_set &a_set) const;
  bool equal(const formula &f) const;
  formula operand() const;
private:
  formula f;
};
