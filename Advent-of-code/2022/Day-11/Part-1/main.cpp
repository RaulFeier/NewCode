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
#define sz(x) (i6) x.size()
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
using i3 = int32_t;
using i6 = int64_t;
using i64 = int64_t;
using u3 = uint32_t;
using u6 = uint64_t;
using u64 = uint64_t;

using d6 = long double;
using d64 = long double;

using p3 = pair<i3, i3>;
using vi3 = vec<i3>;
using vp3 = vec<p3>;

using p6 = pair<i6, i6>;
using p64 = pair<i64, i64>;
using vi6 = vec<i6>;
using vi64 = vec<i64>;
using vd6 = vec<d6>;
using vd64 = vec<d64>;
using vp6 = vec<p6>;
using vp64 = vec<p64>;
using vv = vec<vi6>;
using vs = vec<str>;

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

struct Monkey {
  vector<i6> items;
  i6 d;
  i6 c1;
  i6 c2;
  fn<i6(i6)> process;
  i6 inspected = 0;

public:
  Monkey(vi6 _items, i6 _d, i6 _c1, i6 _c2, fn<i6(i6)> f) {
    this->items = _items;
    this->d = _d;
    this->c1 = _c1;
    this->c2 = _c2;
    this->process = f;
  }

  void pass(i6 item) { items.push_back(item); }

  void run(vec<Monkey> &monkeys) {
    while (!items.empty()) {
      auto val = items.back();
      items.pop_back();
      inspected++;
      auto nval = process(val) / 3;
      int pos = test(nval);
      monkeys[pos].pass(nval);
    }
  }
  i6 test(i6 nval) {
    if (nval % d == 0) {
      return c1;
    } else {
      return c2;
    }
  }
  inline i6 get_inspected() { return inspected; }
};

i6 m19(i6 val) { return val * 19; }

i6 plus6(i6 val) { return val + 6; }

i6 plus3(i6 val) { return val + 3; }

i6 sq(i6 val) { return val * val; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  auto m0 = Monkey({72, 97}, 19, 5, 6, [](i6 old) { return old * 13; });
  auto m1 =
      Monkey({55, 70, 90, 74, 95}, 7, 5, 0, [](i6 old) { return old * old; });
  auto m2 = Monkey({74, 97, 66, 57}, 17, 1, 0, [](i6 old) { return old + 6; });
  auto m3 = Monkey({86, 54, 53}, 13, 1, 2, [](i6 old) { return old + 2; });
  auto m4 = Monkey({50, 65, 78, 50, 62, 99}, 11, 3, 7,
                   [](i6 old) { return old + 3; });
  auto m5 = Monkey({90}, 2, 4, 6, [](i6 old) { return old + 4; });
  auto m6 = Monkey({88, 92, 63, 94, 96, 82, 53, 53}, 5, 4, 7,
                   [](i6 old) { return old + 8; });
  auto m7 = Monkey({70, 60, 71, 69, 77, 70, 98}, 3, 2, 3,
                   [](i6 old) { return old * 7; });

  vec<Monkey> monkeys = {m0, m1, m2, m3, m4, m5, m6, m7};

  for (int i = 0; i < 20; i++) {
    for (auto &m : monkeys) {
      m.run(monkeys);
    }
  }
  vi6 t;
  for (auto &m : monkeys) {
    t.push_back(m.get_inspected());
  }
  srt(t);
  rvs(t);
  cout << t[0] * t[1] << endl;
  return 0; // part 1
}