#include <iostream>
#include <string>
#include <deque>

using namespace std;
deque<char> vect (string n)
{
  deque<char> a;
  for (int i = 0; i < n.size(); ++i)
    a.push_back(n[i]-48);
  return a;
}
void add(deque<char> &a,deque<char> &b)
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

int main(int argc, const char *argv[])
{
  deque<char> a;
  deque<char> b;
  string n;
  cin >> n;
  while ( n != "0" )
  {
    b = vect(n);
    add(a,b);
    cin >> n;
  }
  for (deque<char>::iterator it = a.begin(); it != a.end(); ++it)
    cout << int(*it);
  cout << endl;
  return 0;
}
