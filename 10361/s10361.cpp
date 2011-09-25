#include <iostream>
#include <string>
#include <vector>

int main(int argc, const char *argv[])
{
  int numCases = 0;
  std::cin >> numCases;
  for (int i = 0; i < numCases; ++i)
  {
    std::vector<std::string> l1 (5);
    std::string l1b;
    std::string l2;
    std::string rep;
    char c;
    char buf [101];
    int wordCount;
    wordCount = 0;
    std::cin >> c;
    while (c != '\n')
    {
      if ( wordCount%2 == 0 && c == '<')
        ++wordCount;
      else if ( wordCount%2 == 1 && c == '>')
        ++wordCount;
      else
        l1[wordCount].push_back(c);
      std::cin.get(c);
    }
    rep.append(l1[3]).append(l1[2]).append(l1[1]).append(l1[4]);
    for (int j = 0; j < 5; ++j)
      l1b.append(l1[j]);
    std::cin.getline(buf,101);
    l2 = buf;
    std::cout << l1b << std::endl;
    for (int j = 0; j < l2.size()-3; ++j)
      std::cout << l2[j];
    std::cout << rep << std::endl;

  }
  return 0;
}
