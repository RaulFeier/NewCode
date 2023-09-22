#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.rbegin(), v.rend());

  int i = 2;
  unsigned long long res = 0;

  while (i < n) {
    res += v[i];
    i += 3;
  }

  cout << res << endl;

  return 0;
}

/*
400 + 100 + 200 + 350 + 300 + 250 = 1600

400 350 300 250 200 100
*/