#pragma once

#include "atomic_formula.hpp"

class True : public atomic_formula
{
public:
  True();
  virtual std::ostream& print(std::ostream &out) const;
  virtual bool eval(const valuation &val) const;
};

class False : public atomic_formula
{
public:
  False();
  virtual std::ostream& print(std::ostream &out) const;
  virtual bool eval(const valuation &val) const;
};
