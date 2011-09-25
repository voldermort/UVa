#include <iostream>

int main(int argc, const char *argv[])
{
  int cases;
  int farmers;
  std::cin >> cases;
  int size,anim,envi;
  int tot;
  for (int c = 0; c < cases; ++c)
  {
    std::cin >> farmers;
    tot = 0;
    for (int f = 0; f < farmers; ++f)
    {
      std::cin >> size >> anim >> envi;
      tot += size * envi;
    }
    std::cout << tot << std::endl;
  }
  return 0;
}
