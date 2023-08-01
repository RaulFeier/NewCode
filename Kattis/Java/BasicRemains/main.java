package Kattis.Java.BasicRemains;
import java.math.BigInteger;
import java.util.Scanner;

class BasicRemains {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    while (true) {
      int b = scan.nextInt();
      if (b == 0)
        break;

      BigInteger p = new BigInteger(scan.next(), b);
      BigInteger m = new BigInteger(scan.next(), b);

      System.out.println((p.mod(m)).toString(b));
    }

    scan.close();
  }
}