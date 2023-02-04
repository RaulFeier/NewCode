#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  i64 n, t;
  cin >> n >> t;
  vi64 v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }
  if (t == 1) {
    sort(v.begin(), v.end());
    for (auto &x : v) {
      i64 dif = 7777 - x;
      if (dif != x) {
        i64 l = 0;
        i64 r = v.size() - 1;

        while (r - l > 1) {
          i64 mid = (r + l) / 2;
          if (v[mid] < dif) {
            l = mid + 1;
          } else {
            r = mid; // binary search
          }
        }
        if (v[l] == dif) {
          cout << "Yes" << endl;
          return 0;
        } else if (v[r] == dif) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
    cout << "No" << endl;
  }
  if (t == 2) {
    set<i64> a;
    for (i64 i = 0; i < n; i++) {
      a.insert(v[i]);
    }
    if (a.size() == v.size()) {
      cout << "Unique" << endl;
    } else {
      cout << "Contains duplicate" << endl;
    }
  }
  if (t == 3) {
    sort(v.begin(), v.end());
    i64 crt = 1;
    for (i64 i = 1; i < n; i++) {
      if (v[i] == v[i - 1]) {
        crt++;
      } else {
        if (crt > n / 2) {
          cout << v[i - 1] << endl;
          return 0;
        } else {
          crt = 1;
        }
      }
    }
    cout << -1 << endl;
  }
  if (t == 4) {
    sort(v.begin(), v.end());
    if (n % 2 == 1) {
      cout << v[n / 2] << endl;
    } else {
      cout << v[n / 2 - 1] << " " << v[n / 2] << endl;
    }
  }
  if (t == 5) {
    sort(v.begin(), v.end());
    for (i64 i = 0; i < n; i++) {
      if (v[i] >= 100 && v[i] <= 999) {
        cout << v[i] << " ";
      }
    }
  }
  return 0;
}