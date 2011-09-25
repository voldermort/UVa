#include <iostream>
#include <deque>
#include <stack>

using namespace std;

struct card
{
  char s;
  char v;
};
bool operator == (card& a, card& b)
{
  return a.s == b.s || a.v == b.v;
}
void compress(deque<stack<card> >& dq)
{
  int offset[2] = {3,1};
  for (int i = 1; i < dq.size(); ++i)
    for (int j = 0; j < 2; ++j)
      if ( i - offset[j] >= 0 )
        if( dq[i].top() == dq[i-offset[j]].top() ) 
        {
          dq[i-offset[j]].push(dq[i].top());
          dq[i].pop();
          if (dq[i].empty())
            dq.erase(dq.begin()+i);
          i = i - offset[j] - 1;
          break;
        }
}

int main(int argc, const char *argv[])
{
  char c;
  while ( cin >> c )
  {
    deque<stack<card> > accord;
    if ( c == '#' )
      break;
    else 
      cin.putback(c);
    for (int i = 0; i < 52; ++i)
    {
      card cd;
      stack<card> st;
      cin >> cd.v;
      cin >> cd.s;
      st.push(cd);
      accord.push_back(st);
    }
    compress(accord);
    cout << accord.size() << " pile" << (accord.size()==1?"":"s") << " remaining:";
    for (int i = 0; i < accord.size(); ++i)
      cout << " " << accord[i].size();
    cout << endl;
  }
  return 0;
}
