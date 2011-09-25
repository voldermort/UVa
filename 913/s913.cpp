#include <iostream>

int main(int argc, const char *argv[])
{
  unsigned long long int inp;
  while ( std::cin >> inp ) 
    std::cout << (inp*inp*3 + 6*inp - 15)/2 << std::endl;
  return 0;
}
