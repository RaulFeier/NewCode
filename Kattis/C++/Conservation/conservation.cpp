#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

int solve(int lab_start, vector<vector<int>> &adj, vector<int> &in_degree,
          vector<int> &lab) {
  vector<int> cp_degrees;
  queue<int> q1;
  queue<int> q2;

  for (int i = 0; i < adj.size(); i++) {
    cp_degrees.push_back(in_degree[i]);
    if (in_degree[i] == 0) {
      if (lab[i] == 1) {
        q1.push(i);
      } else {
        q2.push(i);
      }
    }
  }

  int type = lab_start;
  int moves = 0;

  while (!q1.empty() or !q2.empty()) {
    int crt;
    if (type == 1) {
      if (q1.empty()) {
        moves++;
        type = 2;
        continue;
      }
      crt = q1.front();
      q1.pop();
    } else {
      if (q2.empty()) {
        moves++;
        type = 1;
        continue;
      }
      crt = q2.front();
      q2.pop();
    }

    for (auto &c : adj[crt]) {
      cp_degrees[c]--;
      if (cp_degrees[c] == 0) {
        if (lab[c] == 1) {
          q1.push(c);
        } else {
          q2.push(c);
        }
      }
    }
  }

  return moves;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    int n, m;
    cin >> n >> m;

    vector<int> lab(n);
    for (auto &c : lab) {
      cin >> c;
    }

    vector<vector<int>> adj(n);
    vector<int> in_degree(n, 0);

    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      adj[a].push_back(b);
      in_degree[b]++;
    }

    cout << min(solve(1, adj, in_degree, lab), solve(2, adj, in_degree, lab))
         << '\n';
  }

  return 0;
}

/*
1 2 1 2 1

1 2
1 3
2 4
3 4
2 5
3 5
*/