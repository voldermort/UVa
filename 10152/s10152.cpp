#include <iostream>
#include <list>
#include <string>

using namespace std;

void testCase()
{
  int nTurt;
  string w;
  list<string> tu;
  list<string> to;

  cin >> nTurt;
  getline(cin,w);
  for (int i = 0; i < nTurt; ++i)
  {
    getline(cin,w);
    tu.push_front(w);
  }
  for (int i = 0; i < nTurt; ++i)
  {
    getline(cin,w);
    to.push_front(w);
  }
  list<string>::iterator iu = tu.begin();
  list<string>::iterator io = to.begin();
  while ( iu != tu.end() )
  {
    if (*iu != *io)
      iu = tu.erase(iu);
    else
    {
      ++iu;
      ++io;
    }

  }
  for (; io != to.end(); ++io)
    cout << (*io) << endl;
  cout << endl;
}

int main(int argc, const char *argv[])
{
  int testCases;
  cin >> testCases;
  for (int test = 0; test < testCases; ++test)
    testCase();
  return 0;
}
