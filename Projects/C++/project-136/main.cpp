#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using p32 = pair<int32_t, int32_t>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ifstream cin{"3secv.in"};
  ofstream cout{"3secv.out"};

  int16_t tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    vector<int> v(n);

    unordered_map<int, int> m;
    map<p32, int> sub;
    int lenght = n;

    int total_sub = 1;
    int from = 0, where;
    int prev;
    cin >> v[0];
    m[v[0]]++;

    for (int i = 1; i < n; i++) {
      cin >> v[i];
      if (v[i] == prev) {
        total_sub++;
      } else {
        where = i - 1;
        sub[{from, where}] = total_sub;
        prev = v[i];
        total_sub = 1;
      }
      m[v[i]]++;
    }

    int l = 0;
    int r = n - 1;

    while (m.size() > 3) {
      if (v[l] == v[r]) {
        int res_l;
        int res_r;
        for (auto &c : sub) {
          if (c.first.first <= l && l <= c.first.second) {
            res_l = c.second;
          }
          if (c.first.first <= r && r <= c.first.second) {
            res_r = c.second;
          }
        }

        if (res_l >= res_r) {
          if (m[v[r]] == 1) {
            m.erase(v[r]);
          } else {
            m[v[r]]--;
          }
          r--;
        } else {
          if (m[v[l]] == 1) {
            m.erase(v[l]);
          } else {
            m[v[l]]--;
          }
          l++;
        }
      } else if (m[v[l]] >= m[v[r]]) {
        if (m[v[r]] == 1) {
          m.erase(v[r]);
        } else {
          m[v[r]]--;
        }
        r--;
      } else {
        if (m[v[l]] == 1) {
          m.erase(v[l]);
        } else {
          m[v[l]]--;
        }
        l++;
      }
      lenght--;
    }

    cout << lenght << endl;
  }

  return 0;
}

/*
7 7 8 7 7 7 8 8 1 1 1 1 1 2 4
*/