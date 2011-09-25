#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
  int bin;
  string str;
  getline(cin,str);
  getline(cin,str);
  while (str != "___________")
  {
    int bin = 0;
    str = str.substr(2,4) + str.substr(7,3);
    for (int i = 0; i < 7; ++i)
      if (str[i] == 'o')
        bin += 1 << (6-i);
    std::cout << ((char)bin);
    getline(cin,str);
  }
  return 0;
}
