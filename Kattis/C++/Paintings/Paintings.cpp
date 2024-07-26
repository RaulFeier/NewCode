/*

Author: RaulFeier1
Time: 2024-07-25 15:49:01

*/

#ifndef __AHA__HEADER
#define __AHA__HEADER

#include <algorithm>
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
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define all(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rvs(x) reverse(x.begin(), x.end())

#define pq priority_queue
#define fn function
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

using graph = vv;
using matrix = vv;

const d64 EPS = 1 / 1000000.0;
const i64 INF = INT64_MAX / 4;
const i64 NINF = -INF;
const i64 ZERO = 0;
const i64 _0 = ZERO;
const i64 ONE = 1;
const i64 _1 = ONE;

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

#endif

bitset<20> bs;
int N;
vector<int> best;

void best_sol(vector<int> &sol) {
  for (int i = 0; i < N; i++) {
    if (best[i] < sol[i]) {
      break;
    } else if (sol[i] < best[i]) {
      best = sol;
      break;
    }
  }
}

int cnt = 0;

void solve(int pos, vector<int> &sol, map<int, vector<int>> &p) {
  if (pos == N) {
    best_sol(sol);
    cnt++;
    return;
  }

  for (int i = 0; i < N; i++) {
    if (!bs[i]) {
      if (sol.empty()) {
        sol.push_back(i);
        bs[i] = 1;
        solve(pos + 1, sol, p);
        bs[i] = 0;
        sol.pop_back();
      } else {
        bool can_put = true;
        for (auto &c : p[i]) {
          if (sol[pos - 1] == c) {
            can_put = false;
            break;
          }
        }

        if (can_put) {
          sol.push_back(i);
          bs[i] = 1;
          solve(pos + 1, sol, p);
          bs[i] = 0;
          sol.pop_back();
        }
      }
    }
  }
}

void solve() {
  cin >> N;

  map<string, int> m;
  vector<string> s(N);
  best.resize(N, 0);
  cnt = 0;

  for (int i = 0; i < N; i++) {
    string a;
    cin >> a;

    m[a] = i;
    s[i] = a;
    best[i] = N - 1 - i;
  }

  int M;
  cin >> M;

  map<int, vector<int>> p;
  for (int i = 0; i < M; i++) {
    string a, b;
    cin >> a >> b;

    int x = m[a];
    int y = m[b];

    p[x].push_back(y);
    p[y].push_back(x);
  }

  vector<int> sol;
  solve(0, sol, p);
  cout << cnt << '\n';

  for (auto &c : best) {
    cout << s[c] << " ";
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};
#endif

  i64 tct;
  cin >> tct;

  while (tct--) {
    solve();
  }

  return 0;
}

/*

*/
