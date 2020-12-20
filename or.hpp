#pragma once

#include "binary_connective.hpp"

class or_operator : public binary_connective{
public:
  or_operator(const formula &f1, const formula &f2);
  virtual std::string symbol() const;
  virtual bool eval(const valuation &val) const;
};
