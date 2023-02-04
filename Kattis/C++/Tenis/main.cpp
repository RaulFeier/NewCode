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

void print(bool a) {
  // ifstream cin("input.txt");
  // ofstream cout("output.txt");

  if (a) {
    cout << "ne" << endl;
  } else {
    cout << "da" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
#endif

  // ifstream cin("input.txt");
  // ofstream cout("output.txt");

  str name1, name2;
  cin >> name1 >> name2;

  i64 n;
  cin >> n;
  cin.get();
  for (i64 tc : range(n)) {
    str ans;
    getline(cin, ans);
    vi64 nums;
    i64 a = 0;

    for (i64 i : range(ans.size())) {
      if (i == ans.size() - 1) {
        a *= 10;
        a += ans[i] - '0';
      }
      if (ans[i] == ':' or ans[i] == ' ' or i == ans.size() - 1) {
        nums.pb(a);
        a = 0;
      } else {
        a *= 10;
        a += ans[i] - '0';
      }
    }

    vp64 games;
    bool check = false;

    for (i64 i = 0; i < nums.size(); i += 2) {
      games.pb(make_pair(nums[i], nums[i + 1]));
    }

    if (games.size() > 3 or games.size() == 1) {
      check = true;
    }

    if ((games[0].first > games[0].second) and
        (games[1].first < games[1].second) && games.size() == 2) {
      check = true;
    }

    if ((games[0].first < games[0].second) and
        (games[1].first > games[1].second) && games.size() == 2) {
      check = true;
    }

    for (auto &x : games) {
      if ((x.first == 6 && x.second == 5) or (x.first == 5 && x.second == 6)) {
        check = true;
        break;
      }
    }

    for (auto &x : games) {
      if ((x.first > 6 and x.second < 6 and x.first - x.second > 2) or
          (x.first < 6 and x.second > 6 and x.second - x.first > 2)) {
        check = true;
        break;
      }
    }

    if (name1 == "federer") {
      for (auto &x : games) {
        if (x.first < x.second) {
          check = true;
          break;
        }
      }
    } else if (name2 == "federer") {
      for (auto &x : games) {
        if (x.first > x.second) {
          check = true;
          break;
        }
      }
    }

    i64 p1 = 0, p2 = 0;

    for (auto &x : games) {
      if (x.first > x.second) {
        p1++;
      } else {
        p2++;
      }
    }

    if (p1 == p2) {
      check = true;
    } else if (p1 - 2 > p2 or p2 - 2 > p1) {
      check = true;
    }

    if (games.size() >= 3) {
      for (i64 i = 2; i < games.size(); i++) {
        if ((games[i].first > 6 and games[i].second > 6 and
             games[i].first - games[i].second > 2) or
            (games[i].first > 6 and games[i].second > 6 and
             games[i].second - games[i].first > 2)) {
          check = true;
          break;
        }
      }
    }
    for (i64 i = 0; i < 2; i++) {
      if (games[i].first > 6 and games[i].second > 6) {
        if (games[i].first > games[i].second + 1 or
            games[i].first + 1 < games[i].second) {
          check = true;
          break;
        }
      }
    }

    for (auto &x : games) {
      if (x.first < 6 and x.second < 6) {
        check = true;
        break;
      }
    }

    for (auto &x : games) {
      if (x.first == x.second) {
        check = true;
        break;
      }
    }

    if (games.size() >= 3) {
      for (i64 i = 2; i < games.size(); i++) {
        if (games[i].first - 1 == games[i].second or
            games[i].first == games[i].second - 1) {
          check = true;
          break;
        }
      }
    }

    print(check);
  }

  return 0;
}

/*

*/