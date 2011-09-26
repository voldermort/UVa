#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct team
{
  vector<bool> solv;
  vector<int> time;
  int numSolved;
  int tTime;
  int id;
  team():solv(9,false),time(9,0),id(0),numSolved(0),tTime(0),used(false){}
  bool used;
};

bool operator < (const team& a, const team& b)
{
  if ( a.numSolved == b.numSolved )
  {
    if ( a.tTime == b.tTime )
      return a.id < b.id;
    else
      return a.tTime < b.tTime;
  }
  else
    return a.numSolved > b.numSolved;
}

void testCase()
{
  vector<team> c(100);
  for (int i = 0; i < 100; ++i)
    c[i].id = i;
  string line;
  int teamid,prob,time;
  char stat;
  while (1)
  {
    getline(cin,line);
    if ( line == "" )
      break;
    istringstream iss(line);
    iss >> teamid >> prob >> time >> stat;
    c[teamid-1].used = true;
    if ( stat == 'C')
    {
      if ( c[teamid-1].solv[prob] == false)
      {
        c[teamid-1].tTime += time + c[teamid-1].time[prob];
        c[teamid-1].solv[prob] = true;
        c[teamid-1].numSolved += 1;
      }
    }
    else if ( stat == 'I' )
      if ( c[teamid-1].solv[prob] == false)
        c[teamid-1].time[prob] += 20;
  }
  sort(c.begin(),c.end());
  for (int i = 0; i < 100; ++i)
  {
    if ( c[i].used )
      cout << (c[i].id+1) << " " << c[i].numSolved << " " << c[i].tTime << endl;
  }

}

int main(int argc, const char *argv[])
{
  int testCases;
  cin >> testCases;
  string line;
  getline(cin,line);
  getline(cin,line);
  for (int i = 0; i < testCases; ++i)
  {
    testCase();
    if ( i != testCases-1 )
      cout << endl;
  }
  return 0;
}
