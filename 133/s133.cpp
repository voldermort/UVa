#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

int main(int argc, const char *argv[])
{
  int n,k,m;
  cin >> n >> k >> m;
  while ( n!=0 && k!=0 && m!= 0 )
  {
    list<int> p;
    for (int i = 0; i < n; ++i)
      p.push_back(n-i);
    list<int>::reverse_iterator ki = p.rbegin();
    list<int>::iterator mi = p.begin();
    bool first = true;
    while (p.size() > 0)
    {
      if (!first)
        cout << ",";
      first = false;
      for (int i = 0; i < k - 1; ++i)
      {
        ++ki;
        if ( ki == p.rend() )
          ki = p.rbegin();
      }
      for (int i = 0; i < m - 1; ++i)
      {
        ++mi;
        if ( mi == p.end() )
          mi = p.begin();
      }
      if ( *mi == *ki )
      {
        cout << setw(3) << (*ki);
        list<int>::iterator li = mi;
        ++ki;
        ++mi;
        if ( ki == p.rend() )
          ki = p.rbegin();
        if ( mi == p.end() )
          mi = p.begin();
        p.erase(li);
      }
      else
      {
        cout << setw(3) << (*ki) << setw(3) << (*mi);
        list<int>::reverse_iterator li1 = ki;
        list<int>::iterator li2 = mi;
        ++ki;
        ++mi;
        if ( ki == p.rend() )
          ki = p.rbegin();
        if ( mi == p.end() )
          mi = p.begin();
        if ( *mi == *li1 )
          ++mi;
        if ( *ki == *li2 )
          ++ki;
        if ( ki == p.rend() )
          ki = p.rbegin();
        if ( mi == p.end() )
          mi = p.begin();
        p.erase(--li1.base());
        p.erase(li2);
      }
    }
    cout << endl;
    cin >> n >> k >> m;
  }
  return 0;
}
