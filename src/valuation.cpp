#include "valuation.hpp"

valuation::valuation(const atom_set &a_set)
{
    reset(a_set);
}

void valuation::reset(const atom_set &a_set)
{
  m_values.clear();
  for(unsigned it : a_set)
    m_values[it] = false;
}

bool valuation::value(unsigned p) const
{
  return m_values.at(p);
}

bool& valuation::value(unsigned p)
{
  return m_values.at(p);
}

bool valuation::next()
{
  //we generate next valuation by going from right to left
  //and inverting untill we come across 0, where we invert and stop
  //ex. 11011 -> 11100, 11110->11111
  //when we have all 1, thats the end

  auto i = m_values.rbegin();
  auto j = m_values.rend();
  while(i != j)
  {
    i->second = !i->second;
    if(i->second)
    {
      return true;
    }
    ++i;
  }

  return false;
}

std::ostream& valuation::print(std::ostream &out) const
{
  for(auto &it : m_values)
  {
    out << it.second << ' ';
  }
  return out;
}

std::ostream& operator<<(std::ostream &out, const valuation &val)
{
    return val.print(out);
}
