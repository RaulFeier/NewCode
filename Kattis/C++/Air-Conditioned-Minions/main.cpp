#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> lhs, pair<int, int> rhs) {
  if (lhs.second == rhs.second) {
    return lhs.first < rhs.first;
  }
  return lhs.second < rhs.second;
}

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> min(n);

  for (int i = 0; i < n; i++) {
    cin >> min[i].first >> min[i].second;
  }

  sort(min.begin(), min.end(), cmp);
  int t = min[0].second;

  int total = 1;
  for (int i = 1; i < n; i++) {
    if (min[i].first > t) {
      t = min[i].second;
      total++;
    }
  }

  cout << total << endl;

  return 0;
}