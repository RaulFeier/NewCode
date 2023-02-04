package Kattis.Java.Zoom;
import java.util.Scanner;

class Zoom {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    int n = scan.nextInt(), k = scan.nextInt();
    int[] arr = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = scan.nextInt();
    }

    for (int i = k - 1; i < n; i += k) {
      System.out.print(arr[i] + " ");
    }

    System.out.println();

    scan.close();
  }
}
