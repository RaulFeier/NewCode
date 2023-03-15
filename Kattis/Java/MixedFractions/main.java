package Kattis.Java.MixedFractions;
import java.util.Scanner;

class MixedFractions {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    while (true) {

      int a = scan.nextInt();
      int b = scan.nextInt();

      if (a == 0 && b == 0) {
        break;
      }

      System.out.println(a / b + " " + a % b + " / " + b);
    }

    scan.close();
  }
}
