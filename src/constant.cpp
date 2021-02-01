#include "constant.hpp"

True::True()
  :atomic_formula()
{

}

std::ostream& True::print(std::ostream &out) const
{
  return out << "true";
}

bool True::eval(const valuation &val) const
{
    UNUSED(val);
    return true;
}

False::False()
  :atomic_formula()
{

}

std::ostream& False::print(std::ostream &out) const
{
  return out << "false";
}

bool False::eval(const valuation &val) const
{
    UNUSED(val);
    return false;
}
