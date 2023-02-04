package Kattis.Java.JumboJavelin;
import java.util.Scanner;

class JumboJavelin {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

  int n = scan.nextInt();
  int[] arr = new int[n];

  for (int i = 0; i < n; i++) {
    arr[i] = scan.nextInt();
  }

  int res = arr[0];
  for (int i = 1; i < n; i++) {
    res += arr[i];
    res--;
  }

  System.out.println(res);

  scan.close();
 }
}
