#include <bits/stdc++.h>

using namespace std;
int cnt = 0;

bool check(vector<int> &v, vector<pair<int, int>> &eep) {
  int last = v.size() - 1;
  for (int i = 0; i < last; i++) {
    if (i - v[i] == last - v[last] || i + v[i] == last + v[last]) {
      return false;
    }
  }

  for (auto x : eep) {
    if (x.first == last and x.second == v[last]) {
      return false;
    }
  }

  return true;
}

void permutari(int n, vector<int> &perm, vector<pair<int, int>> &eep) {
  if (n == perm.size()) {
    cnt++;
    return;
  }

  for (int i = 0; i < n; i++) {
    bool f = false;
    for (auto x : perm) {
      if (x == i) {
        f = true;
        break;
      }
    }

    if (!f) {
      perm.push_back(i);
      if (check(perm, eep)) {
        permutari(n, perm, eep);
      }
      perm.pop_back();
    }
  }
}

int main() {
  int n, m;

  while (cin >> n >> m) {
    if (n == 0 and m == 0) {
      break;
    }

    vector<int> a;

    vector<pair<int, int>> eep(m);

    for (int i = 0; i < m; i++) {
      cin >> eep[i].first >> eep[i].second;
    }

    permutari(n, a, eep);

    cout << cnt << endl;
    cnt = 0;
  }

  return 0;
}
