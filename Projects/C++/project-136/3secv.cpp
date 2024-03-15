#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

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
    int lenght = n;

    for (int i = 0; i < n; i++) {
      cin >> v[i];
      m[v[i]]++;
    }

    int l = 0;
    int r = n - 1;

    while (m.size() > 3 and l <= r) {
      if (m[v[l]] >= m[v[r]]) {
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


 */