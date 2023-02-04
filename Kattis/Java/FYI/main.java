package Kattis.Java.FYI;
import java.util.Scanner;

class FYI {
    public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);

      int n = scan.nextInt();
      
      if (n < 5550000 || n > 5559999) {
        System.out.println(0);
      } else {
        System.out.println(1);
      }
      
      scan.close();
    }
}
