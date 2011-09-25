#include <iostream>
#include <cctype>

int main(int argc, const char *argv[])
{
  bool prevNL = false;
  char c;
  int count = 0;
  while (std::cin.get(c))
  {
    if (c == 'b')
      c = ' ';
    if (c == '!')
      std::cout << "\n";
    else if (c == '\n')
    {
      if (prevNL)
      {
        std::cout << std::endl;
        prevNL = false;
      }
      else
      {
        std::cout << std::endl;
        prevNL = true;
      }
    }
    else if (isdigit(c))
    {
      count += c-48;
    }
    else
    {
      for (int i = 0; i < count; ++i)
      {
        std::cout << c;
      }
      count = 0;
    }
  }
  return 0;
}
