#include <iostream>
#include <string>

int main(int argc, const char *argv[])
{
  std::string str;
  while (std::cin >> str)
  {
    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    {
      std::cout << (char)((*it)-7);
    }
    std::cout << std::endl;
  }
  return 0;
}
