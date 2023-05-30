#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 next_power_of_two(i64 n) {
  i64 res = 1;
  while (res < n) {
    res *= 2;
  }

  return res;
}

void update(i64 pos, i64 value, vector<i64> &bt) {
  bt[pos] += value;

  pos /= 2;
  while (pos > 0) {
    bt[pos] = bt[pos * 2] + bt[pos * 2 + 1];
    pos /= 2;
  }
}

i64 query(i64 left, i64 right, vector<i64> &bt) {
  i64 res = 0;

  while (left <= right) {
    if (left % 2 == 1) {
      res += bt[left];
      left++;
    }
    if (right % 2 == 0) {
      res += bt[right];
      right--;
    }

    left /= 2;
    right /= 2;
  }

  return res;
}

int main() {
  i64 n, q;
  cin >> n >> q;
  n = next_power_of_two(n);

  vector<i64> bt(2 * n, 0);

  while (q--) {
    char op;
    cin >> op;
    if (op == '+') {
      i64 pos, value;
      cin >> pos >> value;
      update(n + pos, value, bt);
    } else if (op == '?') {
      i64 pos;
      cin >> pos;

      cout << query(n, n + pos - 1, bt) << '\n';
    }
  }

  return 0;
}