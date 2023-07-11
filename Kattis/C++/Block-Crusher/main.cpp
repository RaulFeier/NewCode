/*    ___                       ___           ___
     /\__\          ___        /\  \         /\__\
    /::|  |        /\  \      /::\  \       /:/  /
   /:|:|  |        \:\  \    /:/\ \  \     /:/  /
  /:/|:|__|__      /::\__\  _\:\~\ \  \   /:/  /  ___
 /:/ |::::\__\  __/:/\/__/ /\ \:\ \ \__\ /:/__/  /\__\
 \/__/~~/:/  / /\/:/  /    \:\ \:\ \/__/ \:\  \ /:/  /
       /:/  /  \::/__/      \:\ \:\__\    \:\  /:/  /
      /:/  /    \:\__\       \:\/:/  /     \:\/:/  /
     /:/  /      \/__/        \::/  /       \::/  /
     \/__/                     \/__/         \/__/
*/

#ifndef __AHA__HEADER
#define __AHA__HEADER

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define g0 get<0>
#define g1 get<1>
#define g2 get<2>
#define ft first
#define sd second
#define sz(x) (i64) x.size()
#define psb(x) push_back(x)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define pp(x) pop_back(x)
#define bg(x) x.begin()
#define ed(x) x.end()
#define col(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rvs(x) reverse(x.begin(), x.end())

#define pq priority_queue
#define fn function
#ifdef LOCAL
// #define git stauDBG_MACRO_NO_WARNING
// #include <dbg.h>
#else
#define dbg(...)
#endif
#define endl '\n'

template <typename T> using vec = vector<T>;
template <typename T> using deq = deque<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;

template <typename K, typename V> using hmap = cc_hash_table<K, V>;

using str = string;
using vb = vec<bool>;

using byte = int8_t;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

using d64 = long double;

using p32 = pair<i32, i32>;
using vi32 = vec<i32>;
using vp32 = vec<p32>;

using p64 = pair<i64, i64>;
using vi64 = vec<i64>;
using vd64 = vec<d64>;
using vp64 = vec<p64>;
using vv = vec<vi64>;
using vs = vec<str>;

using dp64 = deq<p64>;
using di64 = deq<i64>;

using mi64 = map<i64, i64>;
using mp64 = map<p64, i64>;
using si64 = set<i64>;
using hi64 = hmap<i64, i64>;

using bs = bitset<64>;

using graph = vv;
using matrix = vv;

const d64 EPS = 1 / 1000000.0;
const i64 INF = INT64_MAX / 4;
const i64 NINF = -INF;
const i64 ZERO = 0;
const i64 _0 = ZERO;
const i64 ONE = 1;
const i64 _1 = ONE;

namespace std {
template <typename T1, typename T2> struct hash<pair<T1, T2>> {
  std::size_t operator()(const pair<T1, T2> &pair) const noexcept {
    return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
  }
};
} // namespace std

template <typename T1, typename T2>
istream &operator>>(istream &stream, pair<T1, T2> &p) {
  stream >> p.ft;
  stream >> p.sd;
  return stream;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &stream, const pair<T1, T2> &p) {
  return stream << p.ft << " " << p.sd;
}

template <typename T> istream &operator>>(istream &stream, vec<T> &v) {
  if (v.empty()) {
    u64 len;
    stream >> len;
    v.assign(len, T());
  }
  for (auto i = 0; i < sz(v); i++) {
    stream >> v[i];
  }
  return stream;
}

template <typename T> ostream &operator<<(ostream &stream, const vec<T> &v) {
  if (!v.empty()) {
    stream << v[0];
  }
  for (auto i = 1; i < sz(v); i++) {
    stream << " " << v[i];
  }
  return stream;
}

template <typename T> inline T pop(vector<T> &stack) {
  T top = stack.back();
  stack.pop_back();
  return top;
}

template <typename T> inline T popb(deq<T> &que) {
  T top = que.back();
  que.pop_back();
  return top;
}

template <typename T> inline T popf(deq<T> &que) {
  T top = que.front();
  que.pop_front();
  return top;
}

template <typename T>
struct number_iterator : std::iterator<random_access_iterator_tag, T> {
  T v;
  number_iterator(T _v) : v(_v) {}
  operator T &() { return v; }
  T operator*() const { return v; }
};
template <typename T> struct number_range {
  T b, e;
  number_range(T b, T e) : b(b), e(e) {}
  number_iterator<T> begin() { return b; }
  number_iterator<T> end() { return e; }
};

template <typename T> number_range<T> range(T e) {
  return number_range<T>(0, e);
}

template <typename T> number_range<T> range(T b, T e) {
  return number_range<T>(b, e);
}

#endif

i64 r, c;
i64 x, y;

using pp6 = pair<i64, p64>;
const i64 DIRX[8] = {1, 1, 1, -1, -1, -1, 0, 0};
const i64 DIRY[8] = {1, 0, -1, 1, 0, -1, 1, -1};

pair<i64, set<p64>> dij(i64 cl, const vv &bl) {
  vv ans(r, vi64(c, INF));
  map<p64, p64> pr;
  pq<pp6, vec<pp6>, greater<pp6>> q;
  ans[0][cl] = bl[0][cl];
  pr[{0, cl}] = {-1, -1};
  q.push({ans[0][cl], {0, cl}});
  while (!q.empty()) {
    pp6 p = q.top();
    q.pop();
    i64 dist = p.ft;
    p64 node = p.second;
    if (dist != ans[node.ft][node.sd]) {
      continue;
    }
    for (int i = 0; i < 8; i++) {
      i64 x = node.ft + DIRX[i];
      i64 y = node.sd + DIRY[i];
      if (x >= 0 && x < r && y >= 0 && y < c) {
        i64 cand = dist + bl[x][y];
        if (cand < ans[x][y]) {
          ans[x][y] = cand;
          q.push({cand, {x, y}});
          pr[{x, y}] = node;
        }
      }
    }
  }
  i64 sol_v = INF;
  i64 sol = -1;
  for (int i = 0; i < c; i++) {
    if (sol_v > ans[r - 1][i]) {
      sol_v = ans[r - 1][i];
      sol = i;
    }
  }
  p64 crt = {r - 1, sol};
  set<p64> res;
  while (crt.ft != -1) {
    res.insert(crt);
    crt = pr[crt];
  }
  return {sol_v, res};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};
#endif
  char ch;
  cin >> r >> c;
  while (r > 0 && c > 0) {
    vv bl(r, vi64(c, 0));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> ch;
        bl[i][j] = ch - '0';
      }
    }
    i64 sol = INF;
    set<p64> solp;
    for (int i = 0; i < c; i++) {
      pair<i64, set<p64>> res = dij(i, bl);
      if (sol > res.ft) {
        sol = res.ft;
        solp = res.sd;
      }
    }
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (solp.count({i, j}) == 0) {
          cout << bl[i][j];
        } else {
          cout << " ";
        }
      }
      cout << endl;
    }
    cout << endl;
    cin >> r >> c;
  }
  return 0;
}