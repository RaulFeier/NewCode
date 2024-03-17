#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  return 0;
}

/*
1 2 3 4 5 6

*/