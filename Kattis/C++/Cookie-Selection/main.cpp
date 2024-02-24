#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using i64 = int64_t;
using p64 = pair<i64, i64>;

typedef tree<p64, null_type, less<p64>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ordered_set t;

  string s;
  i64 _size = 0;
  i64 timer = 0;

  while (cin >> s) {
    if (s == "#") {
      if (_size % 2 == 0) {
        auto p = *t.find_by_order(_size / 2);
        cout << p.first << endl;
        t.erase(p);
      } else {
        auto p = *t.find_by_order((_size + 1) / 2 - 1);
        cout << p.first << endl;
        t.erase(p);
      }

      _size--;
    } else {
      t.insert({stoi(s), timer++});
      _size++;
    }
  }

  return 0;
}

/*
3
4
1
2
 */