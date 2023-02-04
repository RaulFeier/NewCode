package Kattis.Java.ParadoxWithAverages;
import java.util.Scanner;

class ParadoxWithAverages {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    int t = scan.nextInt();
    System.out.println();

    for (int i = 0; i < t; i++) {
      int n = scan.nextInt(), m = scan.nextInt();

      Double q = 0.0, p = 0.0;
      int[] arr = new int[n];

      for (int j = 0; j < n; j++) {
        arr[j] = scan.nextInt();
        q += arr[j];
      }
      q /= n;

      for (int k = 0; k < m; k++) {
        int x = scan.nextInt();
        p += x;
      }
      p /= m;

      int res = 0;
      for (int j = 0; j < n; j++) {
        if (q > arr[j] && arr[j] > p) {
          res++;
        }
      }

      System.out.println(res);
    }

    scan.close();
  }
}