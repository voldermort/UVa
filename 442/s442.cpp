#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

struct mat
{
  int n;
  int m;
  bool bad;
  int c;
  bool used;
  mat ():used(false),c(0),n(0),m(0),bad(false)
  {}
};

mat operator * (mat a,mat b)
{
  mat m;
  m.bad = a.bad || b.bad;
  m.used = (a.used && b.used);
  if ( a.m != b.n )
    m.bad = true;
  m.c = a.c + b.c;
  m.c += a.m*b.m*a.n;
  m.n = a.n;
  m.m = b.m;
  return m;
}

ostream& operator << (ostream& os, mat m)
{
  if ( m.bad || !m.used)
    os << "error";
  else
    os << m.c;
  return os;
}

map<char,mat> mats;

mat parse(istringstream& iss)
{
  char c;
  mat m;
  while (iss >> c)
  {
    if ( c == ')' )
      break;
    else if ( c == '(' )
    {
      if (m.used)
        m = m * parse(iss);
      else
        m = parse(iss);
    }
    else
    {
      if (m.used)
        m = m * mats[c];
      else
        m = mats[c];
    }
  }
  return m;
}

int main(int argc, const char *argv[])
{
  int numMats;
  int n,m;
  char c;
  cin >> numMats;
  for (int i = 0; i < numMats; ++i)
  {
    mat k;
    cin >> c >> n >> m;
    k.n = n;
    k.m = m;
    k.used = true;
    mats[c]=k;
  }
  string testCase;
  while (cin >> testCase)
  {
    istringstream iss(testCase);
    cout << parse(iss) << endl;
  }
  return 0;
}
