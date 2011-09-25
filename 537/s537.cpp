#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>

int main(int argc, const char *argv[])
{
  int testCases;
  std::cin >> testCases;
  // P = 2^2, U = 2^1, I = 2^0
  for (int test = 0; test < testCases; ++test)
  {
    
    double vals[3];
    int givens = 0;
    char c;
    char concept;
    double val;
    std::cin >> concept;
    std::cin.get(c);
    while (c != '\n')
    {
      if (c == '=')
      {
        std::cin >> val;
        std::cin.get(c);
        switch(c)
        {
          case 'm':
            val /= 1000;
            break;
          case 'k':
            val *= 1000;
            break;
          case 'M':
            val *= 1000000;
            break;
          default:
            std::cin.putback(c);
            break;
        }
        switch(concept)
        {
          case 'P':
            vals[2] = val;
            givens |= 4;
            break;
          case 'U':
            vals[1] = val;
            givens |= 2;
            break;
          case 'I':
            vals[0] = val;
            givens |= 1;
            break;
        }
      }
      concept = c;
      std::cin.get(c);
    }
    std::cout << "Problem #" << (test + 1) << std::endl;
    switch(givens)
    {
      case 3:
        printf("P=%.2lfW\n\n",vals[0]*vals[1]);
        break;
      case 5:
        if (vals[0] == 0)
          printf("U=%.2lfV\n\n",0.0);
        else
          printf("U=%.2lfV\n\n",vals[2]/vals[0]);
        break;
      case 6:
        if (vals[1] == 0)
          printf("I=%.2lfA\n\n",0.0);
        else
          printf("I=%.2lfA\n\n",vals[2]/vals[1]);
        break;
    }
  }
  return 0;
}
