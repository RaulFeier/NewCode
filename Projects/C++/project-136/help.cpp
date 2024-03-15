#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define ft first
#define sd second

template <typename T> using vec = vector<T>;
template <typename T> using deq = deque<T>;

typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef string str;
typedef pair<i64, i64> p64;
typedef vec<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi64> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ifstream cin{"3secv.in"};
  ofstream cout{"3secv.out"};

  int16_t t;
  cin >> t;

  while (t--) {
    i32 n;
    cin >> n;

    i32 ll = 0, res = -1, er = 0;
    cc_hash_table<i32, i32> ind;
    set<i32> num;

    i32 v[n];
    cin >> v[0];

    for (i32 i = 1; i <= n; i++) {
      if (i < n) {
        cin >> v[i];
      }

      i32 x = v[i - 1];

      ind[x] = i;

      if (num.count(x)) {
        ll++;
      } else {
        if (num.size() < 3) {
          num.insert(x);
          ll++;
        } else {
          unordered_set<i32> aux;
          i32 k;

          for (i32 j = i - 1; j > 0; j--) {
            aux.insert(v[j - 1]);
            if (aux.size() == 3) {
              k = j;
              break;
            }
          }

          for (auto &c : ind) {
            if (c.sd <= k) {
              num.erase(c.ft);
            }
          }

          res = max(res, ll);
          ll -= k - er;
          er += k - er;
          num.insert(x);
          ll++;
        }
      }
    }

    res = max(res, ll);
    cout << res << endl;
  }

  return 0;
}