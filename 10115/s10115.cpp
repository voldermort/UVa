#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int numWords;
  cin >> numWords;
  while (numWords != 0)
  {
    vector<pair<string,string> > ws;
    string w,p;
    getline(cin,w);
    for (int i = 0; i < numWords; ++i)
    {
      getline(cin,w);
      getline(cin,p);
      ws.push_back(make_pair(w,p));
    }
    getline(cin,w);
    for (vector<pair<string,string> >::iterator it = ws.begin(); it != ws.end(); ++it)
      while (w.find(it->first) != w.npos)
        w.replace(w.find(it->first),(it->first).size(),it->second);
    cout << w << endl;
    cin >> numWords;
  }
  return 0;
}
