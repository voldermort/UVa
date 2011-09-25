#include <iostream>

int main(int argc, const char *argv[])
{
  unsigned long long int a,b;
  while( std::cin >> a >> b)
  {
    std::cout << ((a<b)?b-a:a-b) << std::endl;
  }
  return 0;
}
