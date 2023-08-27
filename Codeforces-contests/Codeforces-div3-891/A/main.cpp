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

#define My_Header

#include <bits/stdc++.h>

using namespace std;

#define ft first
#define sd second
#define sz(x) x.size()
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define pp(x) pop_back(x)
#define ppf(x) pop_front(x)
#define all(x) x.begin(), x.end()
#define srt(x) x.begin(), x.end()
#define rvs(x) revers(all(x))

// functions
#define rep(n) for (long long i = 0; i < n; i++)
#define factorial(n, mod)                                                      \
  if (n > 1)                                                                   \
    return (n * factorial(n - 1, mod)) % mod;                                  \
  else                                                                         \
    return 1;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) return (a * b) / gcd(a, b);

// templates
template <typename T> using vec = vector<T>;
template <typename T> using deq = deque<T>;
template <typename K, typename V> using mp = map<K, V>;

// declarations
using i64 = long long;
using i32 = long;
using i16 = short;
using i8 = char;

using u64 = unsigned long long;
using u32 = unsigned long;
using u16 = unsigned short;
using u8 = unsigned char;

using d64 = long double;

using p64 = pair<i64, i64>;
using p32 = pair<i32, i32>;
using p16 = pair<i16, i16>;
using p8 = pair<i8, i8>;

using vi64 = vec<i64>;
using vi32 = vec<i32>;
using vi16 = vec<i16>;
using vi8 = vec<i8>;

using vd64 = vec<d64>;

using vb = vec<bool>;

using vp64 = vec<p64>;
using vp32 = vec<p32>;
using vp16 = vec<p16>;
using vp8 = vec<p8>;

using vv = vec<vi64>;

using vvp64 = vec<vp64>;

using dp64 = deq<p64>;
using di64 = deq<i64>;

using mi64 = map<i64, i64>;
using si64 = set<i64>;

using bs = bitset<64>;

// constants
const i64 MOD = 1e9 + 7;
const i64 INF = 1e18;
const i64 NINF = -1e18;
const d64 PI = acos(-1);

// templates functions

template <typename T1, typename T2>
istream &operator>>(ifstream &stream, pair<T1, T2> &p) {
  stream >> p.ft >> p.sd;
  return stream;
}

template <typename T1, typename T2>
ostream &operator<<(ofstream &stream, pair<T1, T2> &p) {
  return stream << p.ft << p.sd;
}

template <typename T> istream &operator<<(istream &stream, vec<T> &v) {
  for (auto &x : v)
    stream >> x;
  return stream;
}

template <typename T> ostream &operator<<(ostream &stream, vec<T> &v) {
  for (auto &x : v)
    stream << x << " ";
  return stream;
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

template <typename T> number_range<T> range(T s, T e) {
  return number_range<T>(s, e);
}

inline void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

inline void file() {
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};
}

void solve() {
  i64 n;
  cin >> n;

  i64 t = 0;
  for (i64 i : range(n)) {
    i64 x;
    cin >> x;

    t += x;
  }

  if (t % 2 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  fast();

  i64 tc;
  cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}