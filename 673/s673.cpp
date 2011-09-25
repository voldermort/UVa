#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  string str;
  getline(cin,str);
  while (getline(cin,str))
  {
    bool bal = true;
    stack<char> st;
    for (string::iterator it = str.begin(); it != str.end(); ++it)
    {
      if ( *it == '(' )
        st.push(')');
      else if ( *it == '[' )
        st.push(']');
      else if (st.size() > 0 && st.top() == *it )
        st.pop();
      else
      {
        bal = false;
        break;
      }
    }
    if ( st.size() == 0 && bal)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
