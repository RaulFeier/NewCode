#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> Collats(int n, int count, vector<pair<int, int>> &v) {
  v.push_back({n, count + 1});

  if (n == 1) {
    return v;
  }

  if (n % 2 == 0) {
    return Collats(n / 2, ++count, v);
  } else {
    return Collats(n * 3 + 1, ++count, v);
  }
}

bool bs(pair<int, int> p, vector<pair<int, int>> &vec, int &res) {
  int l = 0;
  int r = vec.size() - 1;

  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (vec[mid].first == p.first) {
      res = mid;
      return true;
    }

    if (vec[mid].first < p.first) {
      l = mid + 1;
    }

    if (vec[mid].first > p.first) {
      r = mid - 1;
    }
  }

  return false;
}

int main() {

  int a, b;
  while (true) {
    cin >> a >> b;

    if (a == 0 and b == 0) {
      break;
    }

    vector<pair<int, int>> p1;
    vector<pair<int, int>> p2;
    p1 = Collats(a, 0, p1);
    p2 = Collats(b, 0, p2);
    p1.pop_back();
    p2.pop_back();

    sort(p2.begin(), p2.end());

    int res;
    for (auto i : p1) {
      if (bs(i, p2, res)) {
        cout << a << " needs " << i.second - 1 << " steps, " << b << " needs "
             << p2[res].second - 1 << " steps, they meet at " << p2[res].first
             << endl;
        break;
      }
    }
  }

  return 0;
}