#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long int ulli;

ulli cyclen(ulli k)
{
  ulli nm;
  if ( k == 1 )
    return 1;
  else if ( (k & 1) == 0 )
    nm = cyclen(k>>1);
  else
    nm = cyclen(k*3+1);
  return nm + 1;
}

int main(int argc, const char *argv[])
{
  ulli i,j;
  while ( cin >> i >> j )
  {
    int a = min(i,j);
    int b = max(i,j);
    ulli max = 0;
    ulli m;
    for (ulli k = a; k <= b; ++k)
    {
      m = cyclen(k);
      if ( m > max )
        max = m;
    }
    cout << i << " " << j << " " << max << endl;
  }
  return 0;
}
