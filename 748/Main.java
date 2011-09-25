import java.math.BigDecimal;
import java.util.Scanner;

class Main
{
  public static void main (String[] args)
  {
    Scanner sc = new Scanner(System.in);
    BigDecimal r;
    BigDecimal a;
    int n;

    while (sc.hasNextBigDecimal())
    {
      r = sc.nextBigDecimal();
      a = r;
      n = sc.nextInt();
      for (int i = 1; i < n; ++i)
        r = r.multiply(a);
      String k = r.toPlainString();
      k = k.replaceAll("0+$","");
      k = k.replaceAll("^0+","");
      System.out.println(k);
    }
  }
}
