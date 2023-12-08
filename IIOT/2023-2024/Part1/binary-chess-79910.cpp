/**
 *    author:  BERNARD B.01
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef B01
#include "deb.h"
#else
#define deb(...)
#endif

const int N = (int) 2e5;

int R, C, n;
int r[N], c[N], p[N], nums[4 * N];
vector<int> mp[4][4 * N];

inline int get(int x) {
  return (p[x] < 0 ? x : (p[x] = get(p[x])));
}

inline void unite(int x, int y) {
  if ((x = get(x)) != (y = get(y))) {
    if (p[x] < p[y]) {
      swap(x, y);
    }
    n -= 1;
    p[y] += p[x];
    p[x] = y;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> C >> n;
  int ptr = 0;
  for (int i = 0; i < n; i++) {
    cin >> r[i] >> c[i];
    nums[ptr++] = r[i];
    nums[ptr++] = c[i];
    nums[ptr++] = r[i] + c[i];
    nums[ptr++] = r[i] - c[i];
  }
  sort(nums, nums + ptr);
  ptr = (int) (unique(nums, nums + ptr) - nums);
  for (int i = 0; i < n; i++) {
    mp[0][(int) (lower_bound(nums, nums + ptr, r[i]) - nums)].push_back(i);
    mp[1][(int) (lower_bound(nums, nums + ptr, c[i]) - nums)].push_back(i);
    mp[2][(int) (lower_bound(nums, nums + ptr, r[i] + c[i]) - nums)].push_back(i);
    mp[3][(int) (lower_bound(nums, nums + ptr, r[i] - c[i]) - nums)].push_back(i);
  }
  memset(p, -1, sizeof p);
  for (int k = 0; k < 4; k++) {
    for (int j = 0; j < ptr; j++) {
      for (int i = 0; i < (int) mp[k][j].size() - 1; i++) {
        unite(mp[k][j][i], mp[k][j][i + 1]);
      }
    }
  }
  const int md = (int) 1e9 + 7;
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans += ans;
    if (ans >= md) {
      ans -= md;
    }
  }
  cout << ans << '\n';
  return 0;
}
