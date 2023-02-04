package Kattis.Java.BookingARoom;
import java.util.Scanner;

class BookingARoom {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    int n = scan.nextInt(), r = scan.nextInt();
    boolean[] arr = new boolean[n];

    for (int i = 0; i < r; i++) {
      int x = scan.nextInt();
      arr[x - 1] = true;
    }

    if (r == n) {
      System.out.println("too late");
    } else {
      for (int i = 0; i < n; i++) {
        if (!arr[i]) {
          System.out.println(i + 1);
          break;
        }
      }
    }

    scan.close();
  }
}