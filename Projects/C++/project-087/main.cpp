#include <bits/stdc++.h>

using namespace std;

int sum(vector<int> &v, int k, int sc) {
  int res = 0;
  for (int i = k; i < sc; i++) {
    res += v[i];
  }

  return res;
}

int main() {
  vector<int> v = {2, -4, -3, 5, -4, 7, 8, -2};

  int n;
  cin >> n;

  int maxq = 0;

  for (int i = 0; i < n; i++) {
    int sc = n - i;

    for (int k = i; k < sc; k++) {
      maxq = max(maxq, sum(v, k, sc));
    }
  }

  cout << maxq << endl;

  return 0;
}