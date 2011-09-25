#include <iostream>
#include <cctype>
#include <set>
#include <string>

int main(int argc, const char *argv[])
{
  char c;
  std::string word = "";
  std::set<std::string> words;
  while (std::cin.get(c))
  {
    if (isalpha(c))
      word.push_back(tolower(c));
    else
    {
      if (word.size() > 0)
      {
        words.insert(word);
        word = "";
      }
    }
  }
  for (std::set<std::string>::iterator it = words.begin(); it != words.end(); ++it)
    std::cout << *it << std::endl;
  return 0;
}
