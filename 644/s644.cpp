#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  int cn = 1;
  string w;
  vector<string> ws;
  bool b = true;
  while (getline(cin,w))
  {
    if (w == "9")
    {
      if ( b )
        cout << "Set " << cn << " is immediately decodable" << endl;
      else
        cout << "Set " << cn << " is not immediately decodable" << endl;
      ++cn;
      b = true;
      ws.clear();
    }
    else
      for (vector<string>::iterator it = ws.begin(); it != ws.end(); ++it)
        if ( (it->size() > w.size() && it->find(w) == 0) 
            || (w.size() > it->size() && w.find(*it) == 0) )
          b = false;
      ws.push_back(w);
  }
}

