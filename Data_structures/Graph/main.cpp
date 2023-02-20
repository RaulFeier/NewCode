#include <bits/stdc++.h>

using namespace std;

class graph {
private:
  vector<vector<long long>> adjlist;
  long long graph_size_lin;
  long long graph_size_col;

public:
  graph(long long size_lin, long long size_col) {
    adjlist.resize(size_lin * size_col);
    graph_size_lin = size_lin;
    graph_size_col = size_col;
  }

  void print() {
    for (int i = 0; i < adjlist.size(); i++) {
      cout << i << ": ";
      for (auto j : adjlist[i]) {
        cout << j << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  graph g(3, 4);

  g.print();
  return 0;
}