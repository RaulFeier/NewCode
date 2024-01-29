#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using i64 = long long;
typedef tree<i64, null_type, less<i64>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    vector<pair<i64, i64>> p(n);

    for (auto &c : p) {
      cin >> c.first >> c.second;
    }

    sort(p.begin(), p.end());

    i64 ans = 0;

    ordered_set s;

    for (auto &c : p) {
      ans += s.size() - s.order_of_key(c.second);

      s.insert(c.second);
    }

    cout << ans << endl;
  }

  return 0;
}

/*
2 6
3 9
4 5
1 8
7 10
-2 100

-2 100
1 8
2 6
3 9
4 5
7 10
*/