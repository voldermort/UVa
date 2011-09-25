#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

struct State
{
  bool isFinal;
  vector<State*> trans;
  State* root;

  State():isFinal(false),trans(26,NULL){root = this;}
  State(State* r):isFinal(false),root(r),trans(26,NULL){}
  ~State()
  {
    for (int i = 0; i < 26; ++i)
      if ( trans[i] != NULL )
        delete trans[i];
  }
  State* operator [] (size_t n) const
  {
    return trans[n];
  }
  void add (string::iterator it, string::iterator ie)
  {
    if ( it == ie )
      isFinal = true;
    else
    {
      const char c = (*it)-97;
      if ( trans[c] == NULL )
        trans[c] = new State(root);
      trans[c]->add(++it,ie);
    }
  }
  bool findStart(string::const_iterator it, string::const_iterator ie)const
  {
    if (it == ie)
      return false;
    const char c = (*it)-97;
    if ( isFinal && root->findEnd(it,ie) )
      return true;
    else if ( trans[c] == NULL )
      return false;
    else
      return trans[c]->findStart(++it,ie);
  }
  bool findEnd(string::const_iterator it, string::const_iterator ie)const
  {
    if (it == ie)
      return isFinal;
    const char c = (*it)-97;
    if ( trans[c] == NULL )
      return false;
    else
      return trans[c]->findEnd(++it,ie);
  }
};

int main(int argc, const char *argv[])
{
  string s;
  State dfa;
  list<string> ws;
  while (cin >> s)
  {
    dfa.add(s.begin(),s.end());
    ws.push_back(s);
  }
  list<string>::iterator it = ws.begin();
  list<string>::iterator ie = ws.end();
  for(; it != ie; ++it)
    if (dfa.findStart(it->begin(),it->end()))
      cout << *it << endl;
  return 0;
}
