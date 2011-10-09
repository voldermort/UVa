/*worst idea ever*/

#include <stdio.h>
#define min(a,b) ((a<b)?a:b)

int main(int argc, const char *argv[])
{
  int b1,g1,c1,b2,g2,c2,b3,g3,c3;
  int bgc,bcg,gbc,cbg,gcb,cgb;
  int bmin;
  while (scanf("%d %d %d %d %d %d %d %d %d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3) > 0)
  {
    bgc = b2 + b3 + g1 + g3 + c1 + c2;
    bcg = b2 + b3 + c1 + c3 + g1 + g2;
    gcb = g2 + g3 + c1 + c3 + b1 + b2;
    gbc = g2 + g3 + b1 + b3 + c1 + c2;
    cbg = c2 + c3 + b1 + b3 + g1 + g2;
    cgb = c2 + c3 + g1 + g3 + b1 + b2;
    bmin = min(bgc,min(bcg,min(gbc,min(cbg,min(gcb,cgb)))));
    if ( bmin == bcg )      fputs("BCG ",stdout);
    else if ( bmin == bgc ) fputs("BGC ",stdout);
    else if ( bmin == cbg ) fputs("CBG ",stdout);
    else if ( bmin == cgb ) fputs("CGB ",stdout);
    else if ( bmin == gbc ) fputs("GBC ",stdout);
    else if ( bmin == gcb ) fputs("GCB ",stdout);
    printf("%d\n",bmin);
  }
  return 0;
}
