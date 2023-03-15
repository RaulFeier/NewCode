package Kattis.Java.FibonacciCycles;
import java.util.Scanner;

class FibonacciCycles {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    int q = scan.nextInt();

    int[] seen = new int[1000];

    for (int i = 0; i < q; i++) {
      int k = scan.nextInt();

      for (int j = 0; j < k; j++) {
        seen[j] = -1;
      }

      System.out.println(Fib(2, 1, 1, 0, seen, k));
    }

    scan.close();
  }

  public static int Fib(int n, int f0, int f1, int f2, int[] seen, int k) {
    f2 = (f0 % k + f1 % k) % k;

    if (seen[f2] != -1) {
      return seen[f2];
    }

    seen[f2] = n;

    f0 = f1;
    f1 = f2;
    n++;

    return Fib(n, f0, f1, f2, seen, k);
  }
}
