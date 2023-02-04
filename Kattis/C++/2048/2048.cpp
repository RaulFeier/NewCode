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
#define sz(x) (i6) x.size()
#define psb(x) push_back(x)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define pp(x) pop_back(x)
#define bg(x) x.begin(x)
#define ed(x) x.end()
#define col(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())

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
using i3 = int32_t;
using i6 = int64_t;
using i64 = int64_t;
using i128 = __int128_t;
using u3 = uint32_t;
using u6 = uint64_t;
using u64 = uint64_t;

using d6 = long double;
using d64 = long double;

using p3 = pair<i3, i3>;
using p64 = pair<i64, i64>;
using vi3 = vec<i3>;
using vp3 = vec<p3>;

using p6 = pair<i6, i6>;
using vi6 = vec<i6>;
using vi64 = vec<i64>;
using vd6 = vec<d6>;
using vd64 = vec<d64>;
using vp6 = vec<p6>;
using vp64 = vec<p64>;
using vv = vec<vi6>;

using dp6 = deq<p6>;
using di6 = deq<i6>;

using mi6 = map<i6, i6>;
using mp6 = map<p6, i6>;
using si6 = set<i6>;
using hi6 = hmap<i6, i6>;

using bs = bitset<64>;

using graph = vv;
using matrix = vv;

const d6 EPS = 1 / 1000000.0;
const i6 INF = INT64_MAX / 4;
const i6 NINF = -INF;
const i6 ZERO = 0;
const i6 _0 = ZERO;
const i6 ONE = 1;
const i6 _1 = ONE;

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
    u6 len;
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

template <typename T> istream &operator>>(istream &stream, deq<T> &v) {
  if (v.empty()) {
    u6 len;
    stream >> len;
    v.assign(len, T());
  }
  for (auto i = 0; i < sz(v); i++) {
    stream >> v[i];
  }
  return stream;
}

template <typename T> ostream &operator<<(ostream &stream, const deq<T> &v) {
  if (!v.empty()) {
    stream << v[0];
  }
  for (auto i = 1; i < sz(v); i++) {
    stream << " " << v[i];
  }
  return stream;
}
#endif

void checkl(i64 v[4][4], i64 k, bool check) {
  for (i64 i = 0; i < 4; i++) {
    if (v[k][i] == 0) // checking if there are any zeros
    {
      check = true;
    }
  }
}

void zerosl(i64 v[4][4], i64 k) {
  vi64 m(4);

  i64 z = 0;
  for (i64 i = 0; i < 4; i++) {
    if (v[k][i] != 0) {
      m[z] = v[k][i];
      z++;
    }
  }

  for (i64 i = m.size(); i < 4; i++) // swaping all the zeros on right side
  {
    m[i] = 0;
  }

  for (i64 i = 0; i < 4; i++) {
    v[k][i] = m[i];
  }
}

void solvel(i64 v[4][4], i64 k) {
  for (i64 i = 0; i < 4; i++) {
    if (v[k][i] == v[k][i + 1] && i != 3) // solving the left side
    {
      v[k][i] = 2 * v[k][i];
      v[k][i + 1] = 0;
    }
  }
}

void left(i64 v[4][4]) {
  for (i64 k = 0; k < 4; k++) {
    checkl(v, k, false);
    if (checkl) {
      zerosl(v, k);
    }
    solvel(v, k);
    zerosl(v, k);
  }
}

void zerosr(i64 v[4][4], i64 k) {
  vi64 m(4);

  i64 z = 0;
  for (i64 i = 3; i >= 0; i--) {
    if (v[k][i] != 0) {
      m[z] = v[k][i];
      z++;
    }
  }

  for (i64 i = m.size(); i < 4; i++) {
    m[i] = 0;
  }

  z = 0;
  for (i64 i = 3; i >= 0; i--) {
    v[k][i] = m[z];
    z++;
  }
}

void solver(i64 v[4][4], i64 k) {
  for (i64 i = 3; i >= 0; i--) {
    if (v[k][i] == v[k][i - 1] && i != 0) // solving the right case
    {
      v[k][i] = 2 * v[k][i];
      v[k][i - 1] = 0;
    }
  }
}

void right(i64 v[4][4]) {
  for (i64 k = 0; k < 4; k++) {
    checkl(v, k, false);
    if (checkl) {
      zerosr(v, k);
    }
    solver(v, k);
    zerosr(v, k);
  }
}

void checkup(i64 v[4][4], i64 i, bool checkup) {
  for (i64 k = 0; k < 4; k++) {
    if (v[k][i] == 0) {
      checkup = true;
    }
  }
}

void zerosup(i64 v[4][4], i64 i) {
  vi64 m(4);

  i64 z = 0;
  for (i64 k = 0; k < 4; k++) {
    if (v[k][i] != 0) {
      m[z] = v[k][i];
      z++;
    }
  }

  for (i64 k = m.size(); k < 4; k++) {
    m[k] = 0;
  }

  for (i64 k = 0; k < 4; k++) {
    v[k][i] = m[k];
  }
}

void solveup(i64 v[4][4], i64 i) {
  for (i64 k = 0; k < 4; k++) {
    if (v[k][i] == v[k + 1][i] && k != 3) // solving the up case
    {
      v[k][i] = 2 * v[k][i];
      v[k + 1][i] = 0;
    }
  }
}

void up(i64 v[4][4]) {
  for (i64 i = 0; i < 4; i++) {
    checkup(v, i, false);
    if (checkup) {
      zerosup(v, i);
    }
    solveup(v, i);
    zerosup(v, i);
  }
}

void zerosdown(i64 v[4][4], i64 i) {
  vi64 m(4);

  i64 z = 0;
  for (i64 k = 3; k >= 0; k--) {
    if (v[k][i] != 0) {
      m[z] = v[k][i];
      z++;
    }
  }

  for (i64 k = m.size(); k < 4; k++) {
    m[k] = 0;
  }

  z = 0;
  for (i64 k = 3; k >= 0; k--) {
    v[k][i] = m[z];
    z++;
  }
}

void solvedown(i64 v[4][4], i64 i) {
  for (i64 k = 3; k >= 0; k--) {
    if (v[k][i] == v[k - 1][i] && k != 0) // solving the down case
    {
      v[k][i] = 2 * v[k][i];
      v[k - 1][i] = 0;
    }
  }
}

void down(i64 v[4][4]) {
  for (i64 i = 0; i < 4; i++) {
    checkup(v, i, false);
    if (checkup) {
      zerosdown(v, i);
    }
    solvedown(v, i);
    zerosdown(v, i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};
#endif

  vector<i64> pozs = {0, 1, 2, 3};

  i64 v[4][4];

  for (i64 i = 0; i < 4; i++) {
    for (i64 j = 0; j < 4; j++) {
      cin >> v[i][j];
    }
  }

  i64 poz;
  cin >> poz;

  if (poz == pozs[0]) {
    left(v);
  } else if (poz == pozs[1]) {
    up(v);
  } else if (poz == pozs[2]) {
    right(v);
  } else {
    down(v);
  }

  for (i64 i = 0; i < 4; i++) {
    for (i64 j = 0; j < 4; j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}