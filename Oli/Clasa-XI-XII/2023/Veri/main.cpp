#include <bits/stdc++.h>

using namespace std;

enum { unvisited = 0, explored = 1, visited = 2 };

vector<int> color;
vector<int> parent;
vector<int> path;

bool cycle(vector<int> &dist, int node, int &end, vector<vector<int>> &g,
           int cnt) {
  int par = parent[node];
  color[node] = explored;
  // dist[node] = min(dist[node], cnt);
  dist[node] = cnt;

  for (auto &c : g[node]) {
    if (color[c] == unvisited) {
      parent[c] = node;
      if (cycle(dist, c, end, g, cnt + 1)) {
        path.push_back(c);
        return true;
      }
    } else if (color[c] == explored) {
      path.push_back(c);
      dist[c] = cnt + 1;
      end = c;
      return true;
    }
  }

  color[node] = visited;
  return false;
}

void bfs(int node, vector<vector<int>> &graph, vector<int> &dist) {
  queue<int> q;
  q.emplace(node);
  int b = dist[node];
  dist.assign(graph.size(), 1e9);
  dist[node] = b;

  while (!q.empty()) {
    auto crt = q.front();
    q.pop();

    for (auto &c : graph[crt]) {
      if (dist[c] > dist[crt] + 1) {
        dist[c] = dist[crt] + 1;
        q.emplace(c);
      }
    }
  }
}

int main() {
  char c;
  cin >> c;

  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n);

  int start, a, b;
  cin >> start >> a >> b;
  start--;
  a--;
  b--;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    graph[x].push_back(y);
  }

  vector<int> dist(n, 1e9);
  color.assign(n, unvisited);
  parent.assign(n, -1);
  int cnt = 0;

  int end;
  cycle(dist, start, end, graph, cnt);
  cout << end << endl;

  path.push_back(start);

  for (auto &c : dist) {
    cout << c << " ";
  }
  cout << endl;

  // for (auto &c : path) {
  //   cout << c + 1 << " ";
  // }
  // cout << endl;

  if (c == '1') {
    bfs(end, graph, dist);

    for (auto &c : dist) {
      cout << c << " ";
    }
    cout << endl;

    cout << max(dist[a], dist[b]) << endl;
  } else {
    bfs(end, graph, dist);

    cout << path.size() - 1 << endl;
    for (int i = path.size() - 1; i >= 0; i--) {
      cout << path[i] + 1 << " ";
    }
    cout << endl;

    for (auto &c : dist) {
      cout << c << " ";
    }
    cout << endl;

    for (auto &c : dist) {
      cout << c << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
0 1 0 0 2 4 3
0 1 2 3 4 5 6

1
7 8
1 3 4
1 2
2 5
5 7
7 6
6 7
6 5
5 3
7 4
*/