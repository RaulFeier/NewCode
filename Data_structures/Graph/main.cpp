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

  void add(long long parent, long long child) {
    adjlist[parent].push_back(child);
  }

  long long size() { return adjlist.size(); }

  void clear() { adjlist.clear(); }

  void pop(long long parent) { adjlist[parent].pop_back(); }

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

  g.add(1, 3);
  g.add(3, 12);
  g.add(3, 11);
  g.pop(3);

  g.print();
  cout << g.size() << endl;
  g.clear();
  cout << g.size() << endl;

  vector<int> a;
  return 0;
}