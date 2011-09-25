#include <iostream>
#include <cstring>

struct str
{
  char s[101];
  int n;
};

int main(int argc, const char *argv[])
{
  str w[100];
  int words = 0;
  int i = 0;
  int maxLength = 0;
  while (std::cin.getline(w[i].s,102))
  {
    w[i].n = strlen(w[i].s);
    if (w[i].n > maxLength)
      maxLength = w[i].n;
    ++i;
  }
  for (int j = 0; j < maxLength; ++j)
  {
    for (int k = i-1; k >=0 ; --k)
    {
      if (w[k].n > j)
        std::cout << w[k].s[j];
      else
        std::cout << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
