#pragma once

#include "atom_set.hpp"
#include "valuation.hpp"
#include <memory>
#include <iostream>
#include <experimental/optional>
#include <typeinfo>
#include <string>

class base_formula;
using formula = std::shared_ptr<base_formula>;
using optional_valuation = std::experimental::optional<valuation>;


class base_formula : public std::enable_shared_from_this<base_formula>{

public:
  base_formula();
  virtual std::ostream& print(std::ostream &out) const = 0;
  virtual unsigned complexity() const = 0;
  virtual bool eval(const valuation &val) const = 0;
  virtual void get_atoms(atom_set &a_set) const;
  virtual bool equal(const formula &f) const;
  virtual ~base_formula();
  optional_valuation is_satisfiable() const;
  optional_valuation is_not_tautology() const;
  bool is_consequence(const formula &f) const;
  bool is_equivalent(const formula &f) const;
  void print_truth_table(std::ostream &out) const;
};

bool operator==(const formula &left, const formula &right);
bool operator!=(const formula &left, const formula &right);
std::ostream& operator<<(std::ostream &out, const formula &f);
