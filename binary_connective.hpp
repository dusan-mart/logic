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
protected:
  template<typename derived>
  formula substitute_impl(const formula &op1, const formula &op2) const;
private:
 formula f1;
 formula f2;
};

template <typename derived>
formula binary_connective::substitute_impl(const formula &op1, const formula &op2) const
{
  if (equal(op1))
  {
    return op2;
  }

  formula child_1, child_2;
  std::tie(child_1, child_2) = operands();
  return std::make_shared<derived>(child_1->substitute(op1, op2), child_2->substitute(op1, op2));
}
