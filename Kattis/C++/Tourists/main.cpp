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

class SegmentTree {
private:
  i64 n;
  vector<i64> tree;
  i64 len;

  void build(vector<i64> &tree, vector<i64> &height) {
    for (i64 i = 1; i < n; i++) {
      this->tree[(i - 1) + len] = height[tree[i - 1]];
    }

    i64 start = len / 2;
    i64 end = len;
    while (start != 0) {
      for (i64 index = start; index < end; index++) {
        this->tree[index] =
            min(this->tree[index * 2], this->tree[index * 2 + 1]);
      }
      start /= 2;
      end /= 2;
    }
  }

  i64 power_of_two(i64 n) {
    i64 crt = 1;
    while (crt < n) {
      crt *= 2;
    }

    return crt * 2;
  }

public:
  SegmentTree(vector<i64> &tree, vector<i64> &height) {
    n = tree.size();
    this->tree.resize(power_of_two(tree.size()), 0);
    len = this->tree.size() / 2;
    build(tree, height);
  }

  i64 query(i64 l, i64 r) {
    l = l + len;
    r = r + len;
    i64 res = 1e9;

    while (l <= r) {
      if (l % 2 == 1) {
        res = min(res, this->tree[l]);
        l++;
      }
      if (r % 2 == 0) {
        res = min(res, this->tree[r]);
        r--;
      }
      r /= 2;
      l /= 2;
    }

    return res;
  }

  void print_tree() {
    for (int index = 1; index < this->tree.size(); index++) {
      cout << this->tree[index] << " ";
    }
    cout << endl;
  }
};

class LCA {
private:
  vector<i64> first;
  vector<bool> visited;
  i64 n;

  void dfs(vector<vector<i64>> &adj, i64 node, i64 h = 1) {
    visited[node] = true;
    height[node] = h;
    first[node] = euler.size();
    euler.push_back(node);

    for (auto &c : adj[node]) {
      if (!visited[c]) {
        dfs(adj, c, h + 1);
        euler.push_back(node);
      }
    }
  }

public:
  vector<i64> height, euler;

  LCA(vector<vector<i64>> &adj, i64 root = 1) {
    n = adj.size();
    height.resize(n);
    first.resize(n);
    visited.assign(n, false);
    euler.reserve(n * 2);
    dfs(adj, root);
  }

  i64 solve(SegmentTree &tree) {
    i64 res = 0;
    for (i64 i = 1; i < n; i++) {
      i64 left = first[i];
      for (i64 j = i + i; j < n; j += i) {
        i64 right = first[j];

        if (left > right) {
          swap(left, right);
          i64 q = tree.query(left, right);
          res += ((height[i] - q) + (height[j] - q)) + 1;
          left = right;
        } else {
          i64 q = tree.query(left, right);
          res += ((height[i] - q) + (height[j] - q)) + 1;
        }
      }
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};
#endif

  i64 n;
  cin >> n;

  vector<vector<i64>> adj(n + 1, vector<i64>());

  for (i64 i : range(n - 1)) {
    i64 a, b;
    scanf("%ld %ld", &a, &b);

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  LCA lca(adj);
  SegmentTree segtree(lca.euler, lca.height);

  // segtree.print_tree();

  cout << lca.solve(segtree) << endl;

  return 0;
}

/*
3 3
6 3
4 2
3 - 2 = 1
3 - 2 = 1
1 + 1 + 1 = 3

2 4
4 2
1 1
4 - 1 = 3
2 - 1 = 1

5 2
10 2
1 1
2 - 1 = 1
2 - 1 = 1

0 1 0 2 1 0 0 2 2 1 1 0 0 0 0 2 3 2 2 1 2 3 1 1 0 0 0 0 0 0 0 2 3 4 3 2 3 2 3 2
1 2 3 4 3 2 1 2 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

*/