package Kattis.Java.CoutingStars;

import java.util.*;

class CoutingStars {
  static class pair {
    int first, second;

    public pair(int first, int second) {
      this.first = first;
      this.second = second;
    }
  }

  static ArrayList<Integer> dirx = new ArrayList<>(Arrays.asList(1, -1, 0, 0));
  static ArrayList<Integer> diry = new ArrayList<>(Arrays.asList(0, 0, 1, -1));

  static void bfs(int lin, int col, int x, int y, boolean vis[][],
                  ArrayList<ArrayList<Integer>> list) {
    ArrayDeque<pair> q = new ArrayDeque<>();

    q.add(new pair(x, y));
    vis[x][y] = true;

    while (!q.isEmpty()) {
      pair crt = q.peek();
      q.remove();

      for (int i = 0; i < 4; i++) {
        int xx = dirx.get(i) + crt.first;
        int yy = diry.get(i) + crt.second;

        if (xx >= 0 && yy >= 0 && xx < lin && yy < col && !vis[xx][yy] &&
            list.get(xx).get(yy) == 0) {
          q.add(new pair(xx, yy));
          vis[xx][yy] = true;
        }
      }
    }
  }

  public static void main(String args[]) {
    Scanner scan = new Scanner(System.in);

    int index = 1;
    while (scan.hasNext()) {
      int lin = scan.nextInt();
      int col = scan.nextInt();

      ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();

      for (int i = 0; i < lin; i++) {
        ArrayList<Integer> interList = new ArrayList<Integer>();

        if (i == 0) {
          String str = scan.nextLine();
        }
        String str = scan.nextLine();

        for (int j = 0; j < col; j++) {

          if (str.charAt(j) == '-') {
            interList.add(0);
          } else {
            interList.add(1);
          }
        }

        list.add(interList);
      }

      boolean[][] vis = new boolean[lin][col];
      int crt = 0;
      for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
          if (list.get(i).get(j) == 0 && !vis[i][j]) {
            bfs(lin, col, i, j, vis, list);
            crt++;
          }
        }
      }

      System.out.println("Case " + index + ": " + crt);
      index++;
    }

    scan.close();
  }
}
