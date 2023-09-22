#include <bits/stdc++.h>

using namespace std;

bool check(pair<int, int> &a, pair<int,int> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

int main() {
  vector<pair<int, int>> v = {{5, 7}, {3, 4}, {1, 8}, {2, 3}, {3, 7}};

  sort(v.begin(), v.end(), check);

  return 0;
}
