#include "or.hpp"

or_operator::or_operator(const formula &f1, const formula &f2)
  :binary_connective(f1,f2)
{

}
std::string or_operator::symbol() const
{
  return "\\/";
}
bool or_operator::eval(const valuation &val) const
{
  formula f1, f2;
  std::tie(f1,f2) = operands();

  return f1->eval(val) || f2->eval(val);
}
