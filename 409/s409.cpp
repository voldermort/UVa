#include <iostream>
#include <vector>
#include <cctype>

void handleCase(int numKeys, int numLines)
{
  std::vector<std::string> keys;
  std::vector<std::string> lines;
  std::vector<int> counts;
  std::string key;
  std::string line;
  int count = 0;
  int max = 0;
  char buff [72];
  size_t offset = 0;
  char c;
  for (int i = 0; i < numKeys; ++i)
  {
    std::cin >> key;
    keys.push_back(key);
  }
  std::cin.get(c);
  for (int i = 0; i < numLines; ++i)
  {
    count = 0;
    std::cin.getline(buff,72);
    lines.push_back(buff);
    for (int k = 0; k < 72; ++k)
      buff[k] = tolower(buff[k]);
    line = buff;
    for (int k = 0; k < numKeys; ++k)
    {
      offset = line.find(keys[k]);
      while (offset != line.npos)
      {
        if (!isalpha(line[offset+keys[k].size()]))
        {
          ++count;
          break;
        }
        offset = line.find(keys[k],offset+1);
      }
    }
    counts.push_back(count);
    if (count > max)
      max = count;
  }
  for (int i = 0; i < numLines; ++i)
    if (counts[i] == max)
      std::cout << lines[i] << std::endl;
}

int main(int argc, const char *argv[])
{
  int numKeys, numLines;
  int count = 1;
  while (std::cin >> numKeys >> numLines)
  {
    std::cout << "Excuse Set #" << count << std::endl;
    handleCase(numKeys,numLines);
    std::cout << std::endl;
    ++count;
  }
  return 0;
}
