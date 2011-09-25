import java.util.Scanner;
import java.math.BigInteger;

class Main
{
  public static void main (String args[])
  {
    Scanner sc = new Scanner(System.in);
    BigInteger a;
    BigInteger b;
    BigInteger r[];
    String op;
    while (sc.hasNextBigInteger())
    {
      a = sc.nextBigInteger();
      op = sc.next();
      b = sc.nextBigInteger();
      r = a.divideAndRemainder(b);
      if ( op.equals("/") )
        System.out.println(r[0]);
      else if ( op.equals("%") )
        System.out.println(r[1]);
    }
  }
}
