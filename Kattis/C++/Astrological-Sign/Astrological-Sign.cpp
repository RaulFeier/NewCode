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

template <typename T>
using vec = vector<T>;
template <typename T>
using deq = deque<T>;
template <typename K, typename V>
using umap = unordered_map<K, V>;

template <typename K, typename V>
using hmap = cc_hash_table<K, V>;

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

namespace std
{
    template <typename T1, typename T2>
    struct hash<pair<T1, T2>>
    {
        std::size_t operator()(const pair<T1, T2> &pair) const noexcept
        {
            return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
        }
    };
} // namespace std

template <typename T1, typename T2>
istream &operator>>(istream &stream, pair<T1, T2> &p)
{
    stream >> p.ft;
    stream >> p.sd;
    return stream;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &stream, const pair<T1, T2> &p)
{
    return stream << p.ft << " " << p.sd;
}

template <typename T>
istream &operator>>(istream &stream, vec<T> &v)
{
    if (v.empty())
    {
        u6 len;
        stream >> len;
        v.assign(len, T());
    }
    for (auto i = 0; i < sz(v); i++)
    {
        stream >> v[i];
    }
    return stream;
}

template <typename T>
ostream &operator<<(ostream &stream, const vec<T> &v)
{
    if (!v.empty())
    {
        stream << v[0];
    }
    for (auto i = 1; i < sz(v); i++)
    {
        stream << " " << v[i];
    }
    return stream;
}

template <typename T>
istream &operator>>(istream &stream, deq<T> &v)
{
    if (v.empty())
    {
        u6 len;
        stream >> len;
        v.assign(len, T());
    }
    for (auto i = 0; i < sz(v); i++)
    {
        stream >> v[i];
    }
    return stream;
}

template <typename T>
ostream &operator<<(ostream &stream, const deq<T> &v)
{
    if (!v.empty())
    {
        stream << v[0];
    }
    for (auto i = 1; i < sz(v); i++)
    {
        stream << " " << v[i];
    }
    return stream;
}

template <typename T>
inline T pop(vector<T> &stack)
{
    T top = stack.back();
    stack.pop_back();
    return top;
}

template <typename T>
inline T popb(deq<T> &que)
{
    T top = que.back();
    que.pop_back();
    return top;
}

template <typename T>
inline T popf(deq<T> &que)
{
    T top = que.front();
    que.pop_front();
    return top;
}

template <typename T>
struct number_iterator : std::iterator<random_access_iterator_tag, T>
{
    T v;
    number_iterator(T _v) : v(_v) {}
    operator T &() { return v; }
    T operator*() const { return v; }
};
template <typename T>
struct number_range
{
    T b, e;
    number_range(T b, T e) : b(b), e(e) {}
    number_iterator<T> begin() { return b; }
    number_iterator<T> end() { return e; }
};

template <typename T>
number_range<T> range(T e)
{
    return number_range<T>(0, e);
}

template <typename T>
number_range<T> range(T b, T e)
{
    return number_range<T>(b, e);
}
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    ifstream cin{"input.txt"};
    ofstream cout{"output.txt"};
#endif

    i64 n;
    cin >> n;

    for (i64 i = 0; i < n; i++)
    {
        i64 a;
        string ans;
        cin >> a >> ans;
    
        if (ans == "Jan")
        {
            if (a <= 20)
            {
                cout << "Capricorn" << endl;
            }
            else if (a > 20)
            {
                cout << "Aquarius" << endl;
            }
        }
        else if (ans == "Feb")
        {
            if (a > 19)
            {
                cout << "Pisces" << endl;
            }
            else if (a < 20)
            {
                cout << "Aquarius" << endl;
            }
        }
        else if (ans == "Mar")
        {
            if (a < 21)
            {
                cout << "Pisces" << endl;
            }
            else if (a > 20)
            {
                cout << "Aries" << endl;
            }
        }
        else if (ans == "Apr")
        {
            if (a > 20)
            {
                cout << "Taurus" << endl;
            }
            else if (a <= 20)
            {
                cout << "Aries" << endl;
            }
        }
        else if (ans == "May")
        {
            if (a <= 20)
            {
                cout << "Taurus" << endl;
            }
            else if (a > 20)
            {
                cout << "Gemini" << endl;
            }
        }
        else if (ans == "Jun")
        {
            if (a > 21)
            {
                cout << "Cancer" << endl;
            }
            else if (a <= 21)
            {
                cout << "Gemini" << endl;
            }
        }
        else if (ans == "Jul")
        {
            if (a <= 22)
            {
                cout << "Cancer" << endl;
            }
            else if (a > 22)
            {
                cout << "Leo" << endl;
            }
        }
        else if (ans == "Aug")
        {
            if (a < 23)
            {
                cout << "Leo" << endl;
            }
            else if (a > 22)
            {
                cout << "Virgo" << endl;
            }
        }
        else if (ans == "Sep")
        {
            if (a < 22)
            {
                cout << "Virgo" << endl;
            }
            else if (a > 21)
            {
                cout << "Libra" << endl;
            }
        }
        else if (ans == "Oct")
        {
            if (a < 23)
            {
                cout << "Libra" << endl;
            }
            else if (a > 22)
            {
                cout << "Scorpio" << endl;
            }
        }
        else if (ans == "Nov")
        {
            if (a < 23)
            {
                cout << "Scorpio" << endl;
            }
            else if (a > 22)
            {
                cout << "Sagittarius" << endl;
            }
        }
        else if (ans == "Dec")
        {
            if (a < 22)
            {
                cout << "Sagittarius" << endl;
            }
            else if (a > 21)
            {
                cout << "Capricorn" << endl;
            }
        }
    }

    return 0;
}

/*

*/