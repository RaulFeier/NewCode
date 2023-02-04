package Kattis.Java.AddTwoNumbers;
import java.util.Scanner;

class AddTwoNumbers {
  public static void main(String[] args) {
    Scanner read = new Scanner(System.in);

    int[] array = new int[2];

    for (int i = 0; i < 2; i++) {
      array[i] = read.nextInt();
    }

    System.out.print(array[0] + array[1]);
    System.out.println();
    read.close();
  }   
}
