#include <iostream>
#include <vector>
#include <string>

int main(int argc, const char *argv[])
{
  std::string cmap(" .xW");
  int ncase;
  std::cin >> ncase;
  for (int c = 0; c < ncase; ++c)
  {
    std::vector<int>p(10,0);
    std::vector<int>d(40,0);
    std::vector<int>n(40,0);
    d[19] = 1;
    for (int k = 0; k < 10; ++k)
      std::cin >> p[k];
    for (int i = 0; i < 50; ++i)
    {
      for (int j = 0; j < 40; ++j)
        std::cout << cmap[d[j]];
      n[0]  = p[d[0]  + d[1]];
      n[39] = p[d[39] + d[38]];
      for (int j = 1; j < 39; ++j)
        n[j] = p[d[j-1] + d[j] + d[j+1]];
      std::cout << std::endl;
      d = n;
    }
    if ( c+1 != ncase )
      std::cout << std::endl;
  }
  return 0;
}
