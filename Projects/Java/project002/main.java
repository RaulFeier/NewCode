package Projects.Java.project002;
import java.util.Scanner;

class MyClass {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    long n = scan.nextLong();

    for (int i = 0; i < n; i++) {
      System.out.println(i + 1 + " Abracadabra");
    }

    scan.close();
  }
}