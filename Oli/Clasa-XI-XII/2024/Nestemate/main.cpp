#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ifstream cin{"nestemate.in"};
  ofstream cout{"nestemate.out"};

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    unordered_map<int, vector<tuple<int, int, int>>> m;
    map<tuple<int, int, int>, int> dist;
    vector<tuple<int, int, int>> v;

    for (int i = 0; i < n; i++) {
      int x, y, z;
      cin >> x >> y >> z;

      unordered_set<int> s;
      s.insert(x);
      s.insert(y);
      s.insert(z);

      for (auto &c : s) {
        m[c].push_back({x, y, z});
      }

      v.push_back({x, y, z});
    }

    queue<tuple<int, int, int>> q;

    dist[v[a - 1]] = 0;
    q.push(v[a - 1]);

    while (!q.empty()) {
      set<int> s;
      auto [x, y, z] = q.front();
      auto crt = q.front();

      s.insert(x);
      s.insert(y);
      s.insert(z);
      q.pop();

      int distt = dist[crt];

      for (auto &cc : s) {
        for (auto &c : m[cc]) {
          if (dist.count(c)) {
            continue;
          } else {
            dist[c] = distt + 1;
            q.push(c);
          }
        }
      }
    }

    int res = dist[v[b - 1]];
    if (res == 0) {
      cout << -1 << '\n';
    } else {
      cout << res << '\n';
    }
  }

  return 0;
}