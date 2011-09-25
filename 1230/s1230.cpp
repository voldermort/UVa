#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
T modOfPow (T b,T e,T m)
{
  T res = 1;
  while ( e > 0)
  {
    if (e & 1 == 1)
      res = (res * b) % m;
    e = e >> 1;
    b = (b*b)%m;
  }
  return res;
}

int main(int argc, const char *argv[])
{
  unsigned long long int x,y,n;
  int testCases;
  cin >> testCases;
  for (int i = 0; i < testCases; ++i)
  {
    cin >> x >> y >> n;
    cout << modOfPow(x,y,n) << endl;
  }
  return 0;
}
