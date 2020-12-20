#pragma once

#include "base_formula.hpp"

class binary_connective : public base_formula
{
public:
  binary_connective(const formula &f1, const formula &f2);
  virtual std::string symbol() const = 0;
  virtual std::ostream& print(std::ostream &out) const;
  virtual unsigned complexity() const;
  virtual void get_atoms(atom_set &a_set) const;
  virtual bool equal(const formula &f) const;
  std::pair<formula, formula> operands() const;

private:
 formula f1;
 formula f2;
};
