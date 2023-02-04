package Kattis.Java.SortTwoNumbers;
import java.util.Scanner;

class SortTwoNumbers {
    public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);

      int a, b;

      a = scan.nextInt();
      b = scan.nextInt();

      if (a > b) {
        System.out.print(b + " " + a);
      } else {
        System.out.print(a + " " + b);
      }

      System.out.println();

      scan.close();
    }
}