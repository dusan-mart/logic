#include "and.hpp"

and_operator::and_operator(const formula &f1, const formula &f2)
  :binary_connective(f1,f2)
{

}
std::string and_operator::symbol() const
{
  return "/\\";
}
bool and_operator::eval(const valuation &val) const
{
  formula f1, f2;
  std::tie(f1,f2) = operands();

  return f1->eval(val) && f2->eval(val);
}

formula and_operator::substitute(const formula &op1, const formula &op2) const
{
  return substitute_impl<and_operator>(op1, op2);
}
