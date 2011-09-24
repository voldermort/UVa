#include <iostream>
#include <string>

using namespace std;

string forw("AEHIJLMOSTUVWXYZ12358");
string back("A3HILJMO2TUVWXY51SEZ8");

bool isPalin (string str)
{
  return string(str.rbegin(),str.rend()) == str;
}

bool isMirror (string str)
{
  string tmp(str);
  for (string::iterator c = str.begin(); c != str.end(); ++c)
    if (forw.find(*c) != forw.npos)
      *c = back[forw.find(*c)];
    else
      return false;
  return string(str.rbegin(),str.rend()) == tmp;
}

int main(int argc, const char *argv[])
{
  bool mir,pal;
  string str;
  while (cin >> str)
  {
    mir = isMirror(str);
    pal = isPalin(str);
    if (mir && pal)
      cout << str << " -- is a mirrored palindrome." << endl << endl;
    else if (!mir && !pal)
      cout << str << " -- is not a palindrome." << endl << endl;
    else if (!mir && pal)
      cout << str << " -- is a regular palindrome." << endl << endl;
    else if (mir && !pal)
      cout << str << " -- is a mirrored string." << endl << endl;
  }
  return 0;
}
