#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

long long int parseInt(string s)
{
  long long int ret;
  istringstream iss(s);
  iss >> ret;
  return ret;
}

vector<long long int> parseLine(string s)
{
  long long int r;
  vector<long long int> ret;
  istringstream iss(s);
  while ( iss >> r )
    ret.push_back(r);
  return ret;
}

int main(int argc, const char *argv[])
{
  string w;
  while (getline(cin,w))
  {
    long long int k;
    vector<long long int> a;
    vector<long long int> b;
    k = parseInt(w);
    getline(cin,w);
    a = parseLine(w);
    b = a;
    for (int i = 1; i < a.size(); ++i)
    {
      b[i] = a[i] + b[i-1]*k;
    }
    cout << "q(x):";
    for (int i = 0; i < b.size()-1; ++i)
      cout << " " << b[i];
    cout << endl << "r = " << b[b.size()-1] << endl << endl;
  }
  return 0;
}
