#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(int argc, const char *argv[])
{
  char buf[13];
  while(cin.getline(buf,13))
  {
    if (buf[0] == '0')
      break;
    while(strlen(buf) > 1)
    {
      int k = 0;
      for (int i = 0; i < strlen(buf); ++i)
        k += buf[i]-'0';
      sprintf(buf,"%d",k);
    }
    cout << buf << endl;
  }
  return 0;
}
