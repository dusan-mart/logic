#include "propositional_logic.hpp"
#include <iostream>

using namespace std;

int main()
{
  formula p1 = make_shared<atom>(1);
  formula p2 = make_shared<atom>(2);
  formula p3 = make_shared<atom>(3);
  formula p4 = make_shared<atom>(4);

  formula f1 = make_shared<and_operator>(p1, p2);
  formula f2 = make_shared<imp>(p3, f1);
  formula f3 = make_shared<not_operator>(f2);
  formula f4 = make_shared<iff>(f3, f1);
  formula f5 = make_shared<or_operator>(f4, p4);


  cout << f5->equal(f4) << endl;
  atom_set a_set;
  f5->get_atoms(a_set);
  for(auto &a : a_set)
    std::cout << "p" << a << ", ";
  std::cout << '\n';

  valuation v{a_set};
  //v.value(0) = true;
  v.value(2) = true;
  cout << f5->eval(v) << '\n';

  optional_valuation ov = f5->is_not_tautology();
  if(ov)
    cout << ov.value() << '\n';
  else
    cout << "not sat" << '\n';

  f5->print_truth_table(cout);

  return 0;
}
