#pragma once

#include "binary_connective.hpp"

class iff : public binary_connective{
public:
  iff(const formula &f1, const formula &f2);
  virtual std::string symbol() const;
  virtual bool eval(const valuation &val) const;
};
