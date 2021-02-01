#pragma once

#include "binary_connective.hpp"

class imp : public binary_connective{
public:
  imp(const formula &f1, const formula &f2);
  virtual std::string symbol() const;
  virtual bool eval(const valuation &val) const;

  virtual formula substitute(const formula &op1, const formula &op2) const;
};
