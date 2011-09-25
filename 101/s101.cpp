#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;
typedef list<int>::iterator litr;
typedef vector<list<int> > vli;
vli world;

struct pos
{
  litr lpos;
  int vpos;
};

pos find(int a)
{
  pos p;
  for (int vpos = 0; vpos < world.size(); ++vpos)
    for (litr lpos = world[vpos].begin(); lpos != world[vpos].end(); ++lpos)
      if ( *lpos == a )
      {
        p.lpos = lpos;
        p.vpos = vpos;
        return p;
      }
}
void sendHome(litr a, litr b)
{
  for (litr it = a; it != b; ++it)
    world[*it].push_back(*it);
}

int main(int argc, const char *argv[])
{
  int numBlocks;
  string act;
  string ont;
  int ia;
  int ib;
  pos a;
  pos b;
  cin >> numBlocks;
  for (int i = 0; i < numBlocks; ++i)
    world.push_back(list<int>(1,i));
  while (1)
  {
    cin >> act;
    if (act == "quit")
      break;
    cin >> ia >> ont >> ib;
    a = find(ia);
    b = find(ib);
    if ( a.vpos == b.vpos )
      continue;
    if ( act == "move" )
    {
      litr n = a.lpos;
      ++n;
      sendHome(n,world[a.vpos].end());
      world[a.vpos].erase(n,world[a.vpos].end());
    }
    if ( ont == "onto" )
    {
      sendHome(++b.lpos,world[b.vpos].end());
      world[b.vpos].erase(b.lpos,world[b.vpos].end());
      b.lpos = world[b.vpos].end();
    }
    else if ( ont == "over" )
    {
      b.lpos = world[b.vpos].end();
    }
    world[b.vpos].insert(b.lpos,a.lpos,world[a.vpos].end());
    world[a.vpos].erase(a.lpos,world[a.vpos].end());
  }
  for (int i = 0; i < numBlocks; ++i)
  {
    cout << i << ":";
    for (litr it = world[i].begin(); it != world[i].end(); ++it)
      cout << " " << (*it);
    cout << endl;
  }
  return 0;
}
