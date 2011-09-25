#include <iostream>

int main(int argc, const char *argv[])
{
  int n,L,rn,caseN=1;
  std::cin >> n >> L;
  rn = n;
  while (n != -1 && L != -1)
  {
    int count = 0;
    while (n>0 && n<=L)
    {
      ++count;
      if (n == 1)
        break;
      else if (n%2 == 0)
        n = n/2;
      else
        n = (3*n)+1;
    }
    std::cout << "Case " << caseN << ": A = " << rn << ", limit = " << L << ", number of terms = " << count << std::endl;
    std::cin >> n >> L;
    rn = n;
    ++caseN;
  }
  return 0;
}
