package Kattis.Java.Watchoutforthosehailstones;
import java.util.Scanner;

class Watchoutforthosehailstones {
  public static long Colats(long n) {
    if (n == 1) {
      return 1;
    }

    if (n % 2 == 0) {
      return n + Colats(n / 2);
    } else {
      return n + Colats(n * 3 + 1);
    }
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    long n = scan.nextLong();

    System.out.println(Colats(n));

    scan.close();
  }
}