package Projects.Java.project006;
import java.util.Scanner;
import java.util.Vector;

class project006 {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    Integer n = scan.nextInt();

    Vector<Integer> v = new Vector<>(n);

    for (int i = 0; i < n; i++) {
      int a;
      a = scan.nextInt();
      v.add(a);
    }

    for (int i = 0; i < n; i++) {
      System.out.print(v.get(i) + " ");
    }

    scan.close();
  }
}
