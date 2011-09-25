#include <iostream>
#include <vector>
#include <string>

int main(int argc, const char *argv[])
{
  int caseNum;
  std::cin >> caseNum;
  while (caseNum != -1)
  {
    std::cout << "Round " << caseNum << std::endl;
    int wrong = 0;
    int guessed = 0;
    bool found = false;
    std::vector<bool> charUsed(26,false);
    std::string sWord;
    std::string sGuess;
    std::cin >> sWord;
    std::cin >> sGuess;
    for (std::string::iterator g = sGuess.begin(); g != sGuess.end(); ++g)
    {
      found = false;
      if (!charUsed[*g-97])
      {
        for (std::string::iterator w = sWord.begin(); w != sWord.end(); ++w)
        {
          if (*g == *w)
          {
            ++guessed;
            found = true;
            charUsed[*g-97]=true;
          }
        }
        if (!found)
        {
          ++wrong;
        }
        if (wrong == 7)
        {
          std::cout << "You lose." << std::endl;
          break;
        }
        if (guessed == sWord.length())
        {
          std::cout << "You win." << std::endl;
          break;
        }
      }
    }
    if (wrong != 7 && guessed != sWord.length())
      std::cout << "You chickened out." << std::endl;
    std::cin >> caseNum;
  }
  return 0;
}
