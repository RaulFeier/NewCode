#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

bool bfs(vector<vector<i64>> &adj, vector<i64> &color, i64 start) {
  queue<i64> q;
  q.push(start);
  color[start] = 0;

  while (!q.empty()) {
    auto crt = q.front();
    q.pop();

    for (auto &c : adj[crt]) {
      if (color[c] == -1) {
        color[c] = 1 - color[crt];
        q.push(c);
      }

      if (color[c] == color[crt]) {
        return false;
        break;
      }
    }
  }

  return true;
}

int main() {
  i64 n;
  cin >> n;

  map<string, i64> m;
  vector<string> ans;

  for (i64 i = 0; i < n; i++) {
    string s;
    cin >> s;

    m[s] = i;
    ans.push_back(s);
  }

  vector<vector<i64>> adj(n);

  i64 t;
  cin >> t;

  for (i64 i = 0; i < t; i++) {
    string a, b;
    cin >> a >> b;
    i64 aa = m[a];
    i64 bb = m[b];

    adj[aa].push_back(bb);
    adj[bb].push_back(aa);
  }

  bool work = true;
  vector<i64> color(n, -1);
  for (i64 i = 0; i < n; i++) {
    if (!adj[i].empty() and color[i] == -1) {
      work = bfs(adj, color, adj[i][0]);
    } else if (adj[i].empty() and color[i] == -1) {
      color[i] = 0;
    }
  }

  if (!work) {
    cout << "impossible" << endl;
  } else {
    for (i64 i = 0; i < color.size(); i++) {
      if (color[i] == 0) {
        cout << ans[i] << " ";
      }
    }
    cout << endl;

    for (i64 i = 0; i < color.size(); i++) {
      if (color[i] == 1) {
        cout << ans[i] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}

/*
3
fuel
lighter
knife
3
fuel lighter
lighter knife
knife fuel

lighter knife
fuel
*/
