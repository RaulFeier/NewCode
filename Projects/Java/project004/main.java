package Projects.Java.project004;
import java.util.Scanner;

class project004 {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    int a = scan.nextInt();

    System.out.println(a);
    System.out.println(sum(a));

    scan.close();
  }

  public static int sum(int k) {
    return k + 1;
  }
}
