#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

#define forn(i,l,h) for (size_t  i = l         ; i < h        ; ++i)

using namespace std;

bool mycomp(string a,string b)
{
  return a+b > b+a;
}

int main(int argc, const char *argv[])
{
  int nLen;
  string n;
  while ( cin >> nLen )
  {
    if ( nLen == 0 )
      break;
    vector<string> v;
    forn(i,0,nLen)
    {
      cin >> n;
      v.push_back(n);
    }
    sort(v.begin(),v.end(),mycomp);
    copy(v.begin(),v.end(),ostream_iterator<string>(cout));
    cout << endl;
  }
  return 0;
}
