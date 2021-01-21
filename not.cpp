#include "not.hpp"

not_operator::not_operator(const formula &f)
  :unary_connective(f)
{

}

std::ostream& not_operator::print(std::ostream &out) const
{
  out << '~';
  return operand()->print(out);
}

bool not_operator::eval(const valuation &val) const
{
  return !operand()->eval(val);
}

formula not_operator::substitute(const formula &op1, const formula &op2) const
{
  if (equal(op1))
  {
    return op2;
  }

  return std::make_shared<not_operator>(operand()->substitute(op1, op2));
}
