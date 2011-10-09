#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

struct mat
{
  int n;
  int s;
  mat(int n_):n(n_),s(0){}
};

bool testcase(istringstream& is)
{
  stack<mat> st;
  st.push(mat(10000000));
  int n;
  while (is >> n)
  {
    if ( n < 0 )
    {
      st.push(mat(-n));
    }
    else
    {
      if ( n == st.top().n )
      {
        st.pop();
        if ( st.size() == 0)
          return false;
        st.top().s += n;
        if ( st.top().s >= st.top().n )
          return false;
      }
      else
      {
        return false;
      }
    }
  }
  return st.size() == 1;
}

int main(int argc, const char *argv[])
{
  string line;
  while(getline(cin,line))
  {
    istringstream is(line);
    if (testcase(is))
      cout << ":-) Matrioshka!" << endl;
    else
      cout << ":-( Try again." << endl;
  }
  return 0;
}
