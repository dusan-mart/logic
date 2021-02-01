#pragma once

#include "atom_set.hpp"

#include <map>
#include <iostream>
#include <iterator>
#include <algorithm>
class valuation{

public:
  valuation(const atom_set &a_set={});
  void reset(const atom_set &a_set);
  bool value(unsigned p) const;
  bool& value(unsigned p);
  bool next();
  std::ostream& print(std::ostream &out) const;

private:
  std::map<unsigned, bool> m_values;
};

std::ostream& operator<<(std::ostream &out, const valuation &v);
