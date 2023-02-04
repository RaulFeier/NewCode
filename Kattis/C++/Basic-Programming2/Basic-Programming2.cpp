#include <bits/stdc++.h>

using namespace std;

using d6 = long double;
using i64 = long long;

int main() {
  i64 n, t;

  cin >> n >> t;
  vector<i64> v(n);

  for (auto &i : v) {
    cin >> i;
  }

  if (t == 1) {
    map<i64, i64> m;
    for (auto &i : v) {
      if (m.count(7777 - i) != 0) {
        cout << "Yes" << endl;
        return 0;
      }
      m[i]++;
    }
    cout << "No" << endl;
  }

  else if (t == 2) {
    set<i64> m;
    for (auto &i : v) {
      m.insert(i);
    }
    if (m.size() == v.size()) {
      cout << "Unique" << endl;
    } else {
      cout << "Contains duplicate" << endl;
    }
  }

  else if (t == 3) {
    map<i64, i64> m;
    for (auto &i : v) {
      m[i]++;
    }
    for (auto i : m) {
      if (i.second > n / 2) {
        cout << i.first << endl;
        return 0;
      }
    }
    cout << "-1" << endl;
  }

  else if (t == 4) {
    sort(v.begin(), v.end());
    if (n % 2 == 1) {
      cout << v[n / 2] << endl;
    } else {
      cout << v[n / 2 - 1] << " " << v[n / 2] << endl;
    }
  }

  else if (t == 5) {
    sort(v.begin(), v.end());
    for (auto &i : v) {
      if (i > 99 && i < 1000) {
        cout << i << " ";
      }
    }
  }
}