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
template <typename K, typename V> using gmap = gp_hash_table<K, V>;
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

const vi64 dirx = {-1, 1, 0, 0};
const vi64 diry = {0, 0, -1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};
#endif

  i64 lin, col;
  cin >> lin >> col;

  vec<vec<char>> building(lin, vec<char>(col));
  queue<p64> fire_points;
  vv fire_dist(lin, vec<i64>(col, INF));
  p64 start_point;

  for (i64 i : range(lin)) {
    for (i64 j : range(col)) {
      cin >> building[i][j];

      if (building[i][j] == 'F') {
        fire_points.push({i, j});
        fire_dist[i][j] = 0;
      } else if (building[i][j] == 'J') {
        start_point = {i, j};
        building[i][j] = '.';
      }
    }
  }

  if (start_point.first == 0 or start_point.first == lin - 1 or
      start_point.second == 0 or start_point.second == col - 1) {
    cout << 1 << endl;
    return 0;
  }

  while (!fire_points.empty()) {
    p64 crt = fire_points.front();
    fire_points.pop();

    for (i64 i : range(4)) {
      i64 x = crt.ft + dirx[i];
      i64 y = crt.sd + diry[i];

      if (x >= 0 && x < lin && y >= 0 && y < col && building[x][y] == '.' &&
          fire_dist[x][y] == INF) {
        fire_points.push({x, y});
        fire_dist[x][y] = fire_dist[crt.first][crt.second] + 1;
      }
    }
  }

  //   for (auto &c : fire_dist) {
  //     for (auto &cc : c) {
  //       cout << cc << " ";
  //     }
  //     cout << endl;
  //   }

  queue<p64> q;
  q.push(start_point);
  vv dist(lin, vec<i64>(col, INF));
  dist[start_point.ft][start_point.sd] = 0;

  i64 sol = INF;

  while (!q.empty()) {
    p64 crt = q.front();
    q.pop();

    for (i64 i : range(4)) {
      i64 x = crt.ft + dirx[i];
      i64 y = crt.sd + diry[i];

      if (x >= 0 && x < lin && y >= 0 && y < col && building[x][y] == '.' &&
          dist[x][y] == INF) {
        if (fire_dist[x][y] > dist[crt.first][crt.second] + 1) {
          q.push({x, y});
          dist[x][y] = dist[crt.first][crt.second] + 1;
          if (x == 0 or x == lin - 1 or y == col - 1 or y == 0) {
            sol = min(sol, dist[x][y]);
          }
        }
      }
    }
  }

  if (sol == INF) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << sol + 1 << endl;
  }

  return 0;
}

/*

*/
