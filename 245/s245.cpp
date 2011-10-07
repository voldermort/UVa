#include <iostream>
#include <deque>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, const char *argv[])
{
  char c;
  string cword;
  deque<string> wlist;
  int n;
  while ( cin.get(c) )
  {
    if ( isalpha(c) )
      cword += c;
    else if ( isdigit(c) )
    {
      cin.putback(c);
      cin >> n;
      if (n == 0)
        break;
      string tword = wlist[n-1];
      wlist.erase(wlist.begin()+n-1);
      wlist.push_front(tword);
      cout << tword;
    }
    else
    {
      if ( cword.size() != 0 )
      {
        cout << cword;
        wlist.push_front(cword);
        cword = "";
      }
      cout << c;

    }
  }
  return 0;
}
