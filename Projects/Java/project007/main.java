package Projects.Java.project007;

import java.util.*;

class project007 {
  static class pair {
    int first, second;
  }

  public static void main(String args[]) {
    Scanner scan = new Scanner(System.in);

    while (scan.hasNext()) {
      int lin = scan.nextInt();
      int col = scan.nextInt();

      ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();

      for (int i = 0; i < lin; i++) {
        ArrayList<Integer> interList = new ArrayList<Integer>();

        for (int j = 0; j < col; j++) {
          int x = scan.nextInt();
          interList.add(x);
        }

        list.add(interList);
      }

      for (ArrayList<Integer> interList : list) {
        for (int x : interList) {
          System.out.print(x + " ");
        }
        System.out.println();
      }
    }

    scan.close();
  }
}