package Kattis.Java.DasBlinkenlights;
import java.util.Scanner;

class DasBlinkenlights {
  public static int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }
    return gcd(b, a % b);
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int a = scan.nextInt(), b = scan.nextInt(), c = scan.nextInt();

    int t = gcd(a, b);

    if ((a / t) * b <= c) {
      System.out.println("yes");
    } else {
      System.out.println("no");
    }

    scan.close();
  }
}
