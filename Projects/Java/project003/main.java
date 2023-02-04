package Projects.Java.project003;
import java.util.Scanner;

class Reverse{ 
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    int n = scan.nextInt();

    int[] array = new int[n];

    for (int i = 0; i < n; i++) {
        array[i] = scan.nextInt();
    }

    for (int i = n - 1; i >= 0; i--) {
      System.out.print(array[i] + " ");
    }
    
    System.out.println();
    scan.close();
 }
}