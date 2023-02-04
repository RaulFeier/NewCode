package Kattis.Java.Speeding;
import java.util.Scanner;

class Speeding {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    int n = scan.nextInt();
    int a = 0;

    int t2 = 0, d2 = 0;
    for (int i = 0; i < n; i++) {
      int t1 = scan.nextInt();
      int d1 = scan.nextInt();

      if (d1 - d2 != 0) {
        if (((d1 - d2) / (t1 - t2)) > a) {
          a = (d1 - d2) / (t1 - t2);
        }
      }
      t2 = t1;
      d2 = d1;
    }

    System.out.println(a);
    scan.close();
  }
}