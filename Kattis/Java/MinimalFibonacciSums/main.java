package Kattis.Java.MinimalFibonacciSums;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Scanner;

class MinimalFibonacciSums {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    int n = scan.nextInt();
    ArrayList<Integer> terms = new ArrayList<Integer>();
    terms.add(1);
    terms.add(1);

    calcFibo(n, terms);

    ArrayDeque<Integer> res = new ArrayDeque<>();

    solve(n, terms, res);

    for (int i : res) {
      System.out.print(i + " ");
    }

    System.out.println();

    scan.close();
  }

  public static void solve(int n, ArrayList<Integer> terms,
                           ArrayDeque<Integer> res) {
    if (n >= 0 && n >= terms.get(terms.size() - 1)) {
      res.addFirst(terms.get(terms.size() - 1));
      solve(n - terms.get(terms.size() - 1), terms, res);
    } else if (n > 0) {
      terms.remove(terms.size() - 1);
      solve(n, terms, res);
    }
  }

  public static void calcFibo(int n, ArrayList<Integer> terms) {
    int next = terms.get(terms.size() - 1) + terms.get(terms.size() - 2);

    if (next > n) {
      return;
    } else {
      terms.add(next);
      calcFibo(n, terms);
    }
  }
}
