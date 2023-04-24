#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int parent(int a, vector<int> &u) {
  int aa = a;
  int p = u[a];

  while (p != a) {
    a = p;
    p = u[a];
  }

  if (u[aa] != p) {
    u[aa] = p;
  }

  return p;
}

void join(i64 a, i64 b, vector<int> &u, vector<int> &r) {
  int pa = parent(a, u);
  int pb = parent(b, u);

  if (pa != pb) {
    if (r[pa] >= r[pb]) {
      u[pb] = pa;
      r[pa]++;
    } else {
      u[pa] = pb;
      r[pb]++;
    }
  }
}

int main() {
  i64 n, q;
  cin >> n >> q;

  vector<int> u(n);
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    u[i] = i;
    r[i] = 1;
  }

  for (int i = 0; i < q; i++) {
    i64 a, b;
    char c;
    cin >> c >> a >> b;

    if (c == '=') {
      join(a, b, u, r);
    }
    if (c == '?') {
      if (parent(a, u) == parent(b, u)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }

  return 0;
}