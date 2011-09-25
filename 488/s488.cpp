#include <iostream>

int main(int argc, const char *argv[])
{
  int inps;
  int amp;
  int freq;
  std::cin >> inps;
  for (int i = 0; i < inps; ++i)
  {
    std::cin >> amp >> freq;
    for (int f = 0; f < freq; ++f)
    {
      for (int a = 0; a < amp; ++a)
      {
        for (int h = 0; h <= a; ++h)
          std::cout << (char)(49+a);
        std::cout << std::endl;
      }
      for (int a = amp-2; a >= 0; --a)
      {
        for (int h = 0; h <= a; ++h)
          std::cout << (char)(49+a);
        std::cout << std::endl;
      }
      if (freq != f+1)
        std::cout << std::endl;
    }
    if (inps != i+1)
      std::cout << std::endl;
  }
  return 0;
}
