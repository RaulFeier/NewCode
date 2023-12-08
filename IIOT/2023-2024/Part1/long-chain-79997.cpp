// @check-accepted: examples NVsmall Nsmall Nprettybig nolimits
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  vector<vector<int>> G(N);
  vector<vector<int>> children(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  function<void(int, int)> init = [&](int u, int parrent) -> void {
    for (const int &v : G[u]) {
      if (v == parrent) {
        continue;
      }
      init(v, u);
      children[u].push_back(v);
    }
  };
  init(0, -1);

  function<bool(const vector<int> &sizes, int, int)> pair_up = [&](const vector<int> &sizes, int len, int skip_id) -> bool {
    for (int l = 0, r = sizes.size() - 1; l < r; l++, r--) {
      l += (l == skip_id);
      r -= (r == skip_id);
      if (l < r && sizes[l] + sizes[r] < len) {
        return false;
      }
    }
    return true;
  };

  function<int(const vector<int> &, int)> solve_odd = [&](const vector<int> &sizes, int len) -> int {
    int l = 0, r = sizes.size() - 1, best = -1;
    // try to find the rightmost one s.t. we can still pair up the other ones
    while (l <= r) {
      int m = (l + r) / 2;
      if (pair_up(sizes, len, m)) {
        l = m + 1;
        best = m;
      } else {
        r = m - 1;
      }
    }

    return best != -1 ? sizes[best] : -1;
  };

  function<int(const vector<int> &, int, int)> solve_even = [&](const vector<int> &sizes, int len, bool must_use_all) -> int {
    // we might choose not to make N / 2 pairs, but N / 2 - 1 (if we can do so, since it is at least as good as doing N - 1 pairs) 
    if (must_use_all) {
      return pair_up(sizes, len, -1) ? 0 : -1;
    }
    int propagate_upper = lower_bound(sizes.begin(), sizes.end(), len) - sizes.begin();
    if (propagate_upper != sizes.size()) {
      auto sizes_clone = sizes;
      sizes_clone.erase(sizes_clone.begin() + propagate_upper);
      int left_one_out = solve_odd(sizes_clone, len);
      if (left_one_out != -1) {
        return left_one_out;
      }
    }

    return pair_up(sizes, len, -1) ? 0 : -1;
  };

  function<int(int, int)> dfs = [&](int u, int len) -> int {
    vector<int> sizes;
    for (const int &v : children[u]) {
      int v_size = dfs(v, len);
      if (v_size == -1) {
        return -1;
      }
      sizes.push_back(v_size + 1);
    }

    sort(sizes.begin(), sizes.end()); // could be moved inside the functions 
    return sizes.size() % 2 > 0 ? solve_odd(sizes, len) : solve_even(sizes, len, (u == 0));
  };

  int l = 1, r = N - 1, answer = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    int check_value = dfs(0, m);
    if (check_value >= m || check_value == 0) {
      l = m + 1;
      answer = m;
    } else {
      r = m - 1;
    }
  }

  cout << answer << "\n";

  return 0;
}
