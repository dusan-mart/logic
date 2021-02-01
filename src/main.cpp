#include "propositional_logic.hpp"
#include <iostream>

using namespace std;

int main()
{
  //making atoms p1, p2, p3 and p4
  formula p1 = make_shared<atom>(1);
  formula p2 = make_shared<atom>(2);
  formula p3 = make_shared<atom>(3);
  formula p4 = make_shared<atom>(4);

  //making formulas (5 operators AND OR NOT IMPLIES IFF)
  formula f1 = make_shared<and_operator>(p1, p2);// p1 /\ p2
  formula f2 = make_shared<imp>(p3, f1); // p_3 => (p_1 /\ p_2)
  cout << "example while making formula: "<< f2 << '\n';
  formula f3 = make_shared<not_operator>(f2);
  formula f4 = make_shared<iff>(f3, f1);
  formula f5 = make_shared<or_operator>(f4, p4);

  cout << "formula 1:" << '\n';
  cout << f5 << "\n\n";

  // formula f6 = make_shared<or_operator>(f1, f3);
  // cout << "formula 2:" << '\n';
  // cout << f6 << '\n';

  // cout << "Checking if formulas 1&2 are equal:";
  // cout << f5->equal(f6) << endl;

  cout << "\n\n\n";
  cout << f5 << "\n";
  atom_set a_set;

  cout << "atoms from formula:" << '\n';
  f5->get_atoms(a_set);
  for(auto &a : a_set)
    std::cout << "p" << a << ", ";
  std::cout << '\n';

  //setting atoms to true of false
  valuation v{a_set};
  v.value(1) = true;
  v.value(2) = true;// p1 and p2 set to true;
  cout << "valuation if p1 and p2 set to true: " << f5->eval(v) << '\n';

  optional_valuation ov = f5->is_satisfiable();
  //checking if formula is satisfiable and printing 1 solution if it is
  if(ov)
    cout << "\nsatisfiable(first found solution for which formula is true): " << ov.value() << '\n';
  else
    cout << "\nnot satisfiable" << '\n';

  optional_valuation ov_2 = f5->is_not_tautology();
  //checking if formula is satisfiable and printing 1 solution if it is
  if(ov_2)
    cout << "not tautology(first found solution for which formula is not true): " << ov_2.value() << '\n';
  else
    cout << "formula is tautology" << '\n';


  cout << "\n\ntruth table:" << '\n';
  f5->print_truth_table(cout);

  return 0;
}
