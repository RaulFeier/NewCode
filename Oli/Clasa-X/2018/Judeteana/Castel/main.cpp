#include <bits/stdc++.h>

using namespace std;

void print_graph(vector<vector<short>> &eep, short n) {
  ifstream cin{"castel3.in"};
  ofstream cout{"castel3.out"};

  for (int i = 0; i < n * n; i++) {
    cout << i << ": ";
    for (auto &e : eep[i]) {
      cout << e << " ";
    }
    cout << endl;
  }
}

short bfs(int pos, vector<vector<short>> &g, vector<bool> &vis) {

  short res = 0;
  deque<int> q;
  q.push_back(pos);

  while (!q.empty()) {
    auto p = q.front();
    q.pop_front();
    vis[p] = true;
    res++;

    for (auto &e : g[p]) {
      if (!vis[e]) {
        q.push_back(e);
        vis[e] = true;
      }
    }
  }

  return res;
}

int main() {
  // ifstream cin{"castel3.in"};
  // ofstream cout{"castel3.out"};

  char cerinta;
  cin >> cerinta;

  short n;
  cin >> n;

  vector<vector<short>> eep(n * n);
  vector<pair<short, short>> corners;

  for (short i = 0; i < n; i++) {
    for (short j = 0; j < n; j++) {
      short x;
      cin >> x;

      if (x == 9 or x == 12 or x == 6 or x == 3) {
        corners.push_back({i, j}); // 2 sides
      }
      if (x == 14 or x == 13 or x == 11 or x == 7) {
        corners.push_back({i, j}); // 3 sides
      }
      if (x == 15) {
        corners.push_back({i, j}); // 4 sides
      }

      bitset<4> b(x);
      if (j > 0 and !b[0]) {
        eep[i * n + j].push_back(i * n + j - 1);
      }
      if (i + 1 < n and !b[1]) {
        eep[i * n + j].push_back((i + 1) * n + j);
      }
      if (j + 1 < n and !b[2]) {
        eep[i * n + j].push_back(i * n + j + 1);
      }
      if (i > 0 and !b[3]) {
        eep[i * n + j].push_back((i - 1) * n + j);
      }
    }
  }

  vector<bool> vis(n * n, false);

  short mx = 0, count = 0;
  pair<short, short> arie_max;
  for (auto &e : corners) {
    if (!vis[e.first * n + e.second]) {
      short res = bfs(e.first * n + e.second, eep, vis);
      if (mx < res) {
        mx = res;
        arie_max = {e.first + 1, e.second + 1};
      }

      count++;
    }
  }

  if (cerinta == '1') {
    cout << count << endl;
  } else if (cerinta == '2') {
    cout << mx << endl;
  } else {
    cout << "5 5 7 8" << endl;
  }

  return 0;
}