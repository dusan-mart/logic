#include "atomic_formula.hpp"

atomic_formula::atomic_formula()
  :base_formula()
{

}

unsigned atomic_formula::complexity() const
{
  return 0;
}

formula atomic_formula::substitute(const formula &op1, const formula &op2) const{
    if(equal(op1))
    {
      return op2;
    }
    return std::const_pointer_cast<base_formula>(shared_from_this());
}
