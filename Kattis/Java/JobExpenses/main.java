package Kattis.Java.JobExpenses;
import java.util.Scanner;

class JobExpenses {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    int n = scan.nextInt();
    int[] arr = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = scan.nextInt();
    }

    int eep = 0;

    for (int i = 0; i < n; i++) {
      if (arr[i] < 0) {
        eep = sum(eep, arr[i]);
      }
    }

    System.out.println(eep);

    scan.close();
  }

  public static int sum(int eep, int next) {
    return eep + (-1 * next);
  }
}
