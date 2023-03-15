package Kattis.Java.CollatzConjecture;

import java.util.ArrayList;
import java.util.Scanner;

class CollatzConjecture {

  public static void main(String[] args) {
    class Pair<Key, Value> {
      private Key key;
      private Value value;

      public Pair(Key key, Value value) {
        this.key = key;
        this.value = value;
      }
    }

    Scanner scan = new Scanner(System.in);

    int n = scan.nextInt();

    ArrayList<Pair<Integer, Integer>> arr =
        new ArrayList<Pair<Integer, Integer>>(n);

    for (int i = 0; i < n; i++) {
      arr.add(new Pair(1, 2));
    }

    for (int i = 0; i < n; i++) {
      System.out.print(arr.get(i));
    }

    scan.close();
  }

  public static int Col(int n, int count) {
    if (n == 1) {
      return count;
    }

    if (n % 2 == 0) {
      return Col(n / 2, ++count);
    }

    return Col(n * 3 + 1, ++count);
  }
}

/*
22 1
11 2
34 3
17 4
52 5
26 6
13 7
40 8
20 9
10 10
5 11
16 12
8 13
4 14
2 15
1 16
*/