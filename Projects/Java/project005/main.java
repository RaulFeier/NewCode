package Projects.Java.project005;
import java.util.Scanner;

class project005 {
  static public void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    int n = scan.nextInt();
    int[] arr = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = scan.nextInt();
    }

    System.out.println(arr);
    scan.close();
  }
}
