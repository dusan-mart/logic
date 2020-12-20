#pragma once

#include "unary_connective.hpp"

class not_operator : public unary_connective{
public:
  not_operator(const formula &f);
  virtual std::ostream& print(std::ostream &out) const;
  virtual bool eval(const valuation &val) const;
};
