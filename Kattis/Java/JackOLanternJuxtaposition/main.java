package Kattis.Java.JackOLanternJuxtaposition;
import java.util.Scanner;

class JackOLanternJuxtaposition {
    public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);

      int a = scan.nextInt(), b = scan.nextInt(), c = scan.nextInt();

      System.out.println(a * b * c);

      scan.close();
    }
}
