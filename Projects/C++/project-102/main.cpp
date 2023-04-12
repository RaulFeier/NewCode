#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int parent(int a, vector<int> &u) {
  int aa = a;
  int p = u[a];

  return p;
}

void join(i64 a, i64 b, vector<int> &u, vector<int> &r) {
  int pa = parent(a, u);
  int pb = parent(b, u);

  if (pa != pb) {
  }
}

int main() {
  i64 n, q;
  cin >> n >> q;

  vector<int> u(n);
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    u[i] = i;
    r[i] = i;
  }

  for (int i = 0; i < q; i++) {
    i64 a, b;
    char c;
    cin >> c >> a >> b;

    if (c == '=') {
      join(a, b, u, r);
    }
  }

  return 0;
}