#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<int> in_degree(n, 0);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    in_degree[b]++;
    adj[a].push_back(b);
  }

  int start = 0;
  queue<int> q;

  for (int i = 0; i < in_degree.size(); i++) {
    if (in_degree[i] == 0) {
      q.push(i);
    }
  }

  vector<int> sol;
  while (!q.empty()) {
    auto crt = q.front();
    q.pop();

    sol.push_back(crt);
    for (auto &c : adj[crt]) {
      in_degree[c]--;
      if (in_degree[c] == 0) {
        q.push(c);
      }
    }
  }

  if (sol.empty()) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    for (auto &c : sol) {
      cout << c + 1 << endl;
    }
  }

  return 0;
}