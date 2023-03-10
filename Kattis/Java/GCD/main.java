package Kattis.Java.GCD;
import java.util.Scanner;

class GCD {
  public static int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }

    return gcd(b, a % b);
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    int a = scan.nextInt();
    int b = scan.nextInt();

    System.out.println(gcd(a, b));

    scan.close();
  }
}
