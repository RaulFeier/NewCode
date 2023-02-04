#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  i64 n, a;
  cin >> n;
  vi64 v(n);

  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] == 0) {
      a = i;
    }
  }

  vi64 x = v;

  vector<vi64> l(n);

  l[0] = v;

  i64 index = 1;

  for (i64 i = a; i > 0; i--) {
    swap(v[i], v[i - 1]);
    l[index] = v;
    index++;
  }

  for (i64 i = a + 1; i < n; i++) {
    swap(x[i], x[i - 1]);
    l[index] = x;
    index++;
  }

  i64 sum = -1e9;
  for (i64 i = 0; i < n; i++) {
    i64 s = 0;
    for (i64 j = 0; j < n; j++) {
      s += l[i][j];
    }
    sum = max(s, sum);
  }

  cout << sum << endl;

  return 0;
}