#include <iostream>

int getGap (char str [])
{
  int i = 0;
  int begin = 0;
  int end = 0;
  for (i = 0; i < 25; ++i)
    if (str[i] != 'X')
      break;
  begin = i;
  for (; i < 25; ++i)
    if (str[i] == 'X')
      break;
  end = i;
  return end - begin;
}

int main(int argc, const char *argv[])
{
  while (true)
  {
    int n;
    char str[30];
    int leastGap = 25;
    int gap = 0;
    int total = 0;
    std::cin >> n;
    if (n == 0)
      break;
    std::cin.getline(str,30);
    for (int k = 0; k < n; ++k)
    {
      std::cin.getline(str,30);
      gap = getGap(str);
      total += gap;
      leastGap = leastGap<gap?leastGap:gap;
    }
    std::cout << (total - leastGap * n) << std::endl;
  }
  return 0;
}
