#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

int main(int argc, const char *argv[])
{
  string a;
  string b;
   
  while (getline(cin,a))
  {
    getline(cin,b);
    map<char,int> ca;
    map<char,int> cb;
    for (string::iterator it = a.begin(); it < a.end(); ++it)
      (*(ca.insert(pair<char,int>(*it,0)).first)).second++;
    for (string::iterator it = b.begin(); it < b.end(); ++it)
      (*(cb.insert(pair<char,int>(*it,0)).first)).second++;
    for (map<char,int>::iterator it = ca.begin(); it != ca.end(); ++it)
      if (cb.count((*it).first) > 0)
        for (int i = 0; i < ca[(*it).first] && i < cb[(*it).first]; ++i)
          cout << (*it).first;
    cout << endl;
  }

  return 0;
}
