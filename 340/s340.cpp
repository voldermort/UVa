#include <iostream>
#include <deque>
#include <iterator>
#include <sstream>
#include <algorithm>
#define fori(i,c) for (size_t  i = 0; i < c.size(); ++i)

using namespace std;

typedef deque<int> di;

template <typename T>
T splitline()
{
  typedef istream_iterator<typename T::value_type> U;
  string line;
  getline(cin,line);
  istringstream iss (line);
  return T(U(iss),U());
}

void testCase(int len,int num)
{
  cout << "Game " << num << ":" << endl;
  di code(splitline<di>());
  while (1)
  {
    int strong = 0;
    int weak = 0;
    di g(splitline<di>());
    di s(code);
    if ( g[0] == 0 )
      break;
    fori(i,g)
      if ( g[i] == s[i] )
      {
        g.erase(g.begin()+i);
        s.erase(s.begin()+i);
        --i;
        ++strong;
      }
    fori(a,g)
      fori(b,s)
        if ( g[a] == s[b] )
        {
          g.erase(g.begin()+a);
          s.erase(s.begin()+b);
          ++weak;
          --a;
          --b;
        }
    cout << "    (" << strong << "," << weak << ")" << endl;
  }
}

int main(int argc, const char *argv[])
{
  int mLen;
  int tCase = 1; 
  string gbg;
  while ( cin >> mLen )
  {
    getline(cin,gbg);
    if ( mLen != 0 )
      testCase(mLen,tCase++);
  }
  return 0;
}
