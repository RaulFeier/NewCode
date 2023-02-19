#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 matrix[1000][1000];
i64 cmatrix[1000][1000];

i64 dirx[] = {1, -1, 0, 0};
i64 diry[] = {0, 0, -1, 1};
string cmd[] = {"down", "up", "left", "right"};
string rcmd[] = {"up", "down", "right", "left"};

i64 res;
set<pair<i64, i64>> vis;

void dfs(int x, int y) {
  if (res != 0) {
    return;
  }

  vis.insert({x, y});

  for (i64 i = 0; i < 4; i++) {
    i64 xx = x + dirx[i];
    i64 yy = y + diry[i];

    if (vis.count({xx, yy}) == 0) {
      cout << cmd[i] << endl;
      string ans;
      cin >> ans;
      if (ans == "wall") {
        continue;
      }
      if (ans == "wrong") {
        res = -1;
        return;
      }

      if (ans == "solved") {
        res = 1;
        return;
      }
      if (ans == "ok") {
        dfs(xx, yy);
        if (res == 0) {
          cout << rcmd[i] << endl;
          cin >> ans;
          if (ans == "wrong") {
            res = -1;
            return;
          }
        } else {
          return;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};
#endif

  res = 0;
  dfs(0, 0);
  if (res == 0) {
    cout << "no way out" << endl;
  }

  return 0;
}
