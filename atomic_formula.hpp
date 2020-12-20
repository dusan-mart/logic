#pragma once

#include "base_formula.hpp"

class atomic_formula : public base_formula
{
public:
  atomic_formula();

  virtual unsigned complexity() const;
};
