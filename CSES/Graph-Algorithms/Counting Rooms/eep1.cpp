#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 n;

void bfs(i64 start, vector<vector<i64>> &g) {
  vector<bool> visit(n, false);
  vector<i64> dist(n, 0);
  int d = 0;

  visit[start] = true;
  deque<i64> q;
  q.push_back(start);

  while (!q.empty()) {
    int crt = q.front();
    d++;
    q.pop_front();

    for (auto c : g[crt]) {
      if (!visit[c]) {
        visit[c] = true;
        dist[c] = d;
        q.push_back(c);
      }
    }
  }
}

int main() {
  cin >> n;

  vector<vector<i64>> g(n);
  //   vec<vec<i64>> visit(lin, vector<i64>(col, 0));

  for (i64 i = 0; i < n - 1; i++) {
    i64 a, b;
    cin >> a >> b;

    a--;
    b--;

    g[a].push_back(b);
    g[b].push_back(a);
  }
}

/*
4
1 2
4 3
2 3
*/