#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }

  return a.first < b.first;
}

int main() {
  i64 n, l, w;

  while (cin >> n >> l >> w) {
    vector<pair<i64, i64>> v(n);

    for (auto &x : v) {
      cin >> x.first >> x.second;
      if (x.second * 2 < w) {
        v.pop_back();
      }
    }

    sort(v.begin(), v.end(), cmp);

    i64 crt;
    i64 circles = 0;
    bool found = false;

    for (i64 i = 0; i < v.size(); i++) {
      if (v[i].first == v[i + 1].first and i != v.size() - 1) {
        continue;
      } else {
        if (circles == 0) {
          crt = v[i].first - v[i].second;
          if (crt > 0) {
            found = true;
            break;
          } else {
            crt = v[i].first + v[i].second;
          }
        }
        circles++;
      }
    }

    if (found) {
      cout << -1 << endl;
      continue;
    }
  }

  return 0;
}

/*
5 3
4 1
1 2
7 2
10 2
13 3
16 2
19 4

1 2
4 1
5 3
7 2
10 2
13 3
16 2
19 4


*/