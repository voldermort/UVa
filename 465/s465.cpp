#include <iostream>
#include <deque>
#include <string>

using namespace std;

ostream& operator << (ostream& os,deque<char> d)
{
  deque<char>::iterator it = d.begin();
  while ( *it == 0 && it != d.end())
    ++it;
  if ( it == d.end() )
    os << "0";
  else
    for (; it != d.end(); ++it)
      os << int(*it);
  return os;
}

bool operator > (deque<char> a, deque<char> b)
{
  while (a.size() > 0 && a[0] == 0)
    a.pop_front();
  while (b.size() > 0 && b[0] == 0)
    b.pop_front();
  if (a.size() != b.size())
    return a.size() > b.size();
  deque<char>::iterator ia = a.begin();
  deque<char>::iterator ib = b.begin();
  while (1)
  {
    if (ia == a.end() && ib == b.end())
     return false;
    else if ( *ia < *ib )
      return false;
    else if ( *ia > *ib )
      return true;
    ++ia;
    ++ib;
  }
  return 0;
}

deque<char> splitter (string s)
{
  deque<char> d;
  for (int i = 0; i < s.size(); ++i)
    d.push_back(s[i]-48);
  return d;
}

void add(deque<char> &a,deque<char> b)
{
  char c = 0;
  char t = 0;
  int i;
  if (a.size() < b.size())
    swap(a,b);
  deque<char>::reverse_iterator ai = a.rbegin();
  deque<char>::reverse_iterator bi = b.rbegin();
  for (;bi != b.rend(); ++bi,++ai)
  {
    t = *ai + *bi +c;
    *ai = t%10;
    c = t/10;
  }
  for (;ai != a.rend(); ++ai)
  {
    t = *ai + c;
    *ai = t%10;
    c = t/10;
  }
  if ( c != 0 )
    a.push_front(c);
}

deque<char> mult (deque<char>& a, deque<char>& b)
{
  deque<char> total;
  int bsize = b.size();
  int shift = 0;
  for (deque<char>::reverse_iterator ib = b.rbegin(); ib != b.rend(); ++ib)
  {
    deque<char> crow(shift,0);
    deque<char> cary(++shift,0);
    for (deque<char>::reverse_iterator ia = a.rbegin(); ia != a.rend(); ++ia)
    {
      crow.push_front( ((*ib) * (*ia)) % 10);
      cary.push_front( ((*ib) * (*ia)) / 10);
    }
    add(crow,cary);
    add(total,crow);
  }
  return total;
}

int main(int argc, const char *argv[])
{
  string wa;
  string wb;
  deque<char> a;
  deque<char> b;
  deque<char> r;
  deque<char> m = splitter("2147483647");
  char c;
  while ( cin >> wa >> c >> wb)
  {
    a = splitter(wa);
    b = splitter(wb);
    r = splitter(wa);
    if ( c == '+' )
      add(r,b);
    else
      r = mult(a,b);
    cout << wa << " " << c << " " << wb << endl;
    if ( a > m ) 
      cout << "first number too big" << endl;
    if ( b > m )
      cout << "second number too big" << endl;
    if ( r > m )
      cout << "result too big" << endl;
  }
  return 0;
}
