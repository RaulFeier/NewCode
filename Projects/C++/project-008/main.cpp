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
#endif

i64 matrix[1000][1000];
i64 cmatrix[1000][1000];
vi64 pozx = {1, -1, 0, 0};
vi64 pozy = {0, 0, 1, -1};

void dfs(i64 i, i64 j, i64 r, i64 c, i64 clr, i64 val)
{
    cmatrix[i][j] = clr;

    for (i64 k = 0; k < 4; k++)
    {
        i64 x = i + pozx[k];
        i64 y = j + pozy[k];

        if (x >= 0 && x < r && y >= 0 && y < c)
        {
            if (matrix[x][y] == val && cmatrix[x][y] == -1)
            {
                dfs(x, y, r, c, clr, val);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    ifstream cin{"input.txt"};
    ofstream cout{"output.txt"};
#endif

    i64 r, c;
    cin >> r >> c;

    for (i64 i = 0; i < r; i++)
    {
        for (i64 j = 0; j < c; j++)
        {
            char a;
            cin >> a;
            matrix[i][j] = a - '0';
            cmatrix[i][j] = -1;
        }
    }

    i64 clr = 0;
    for (i64 i = 0; i < r; i++)
    {
        for (i64 j = 0; j < c; j++)
        {
            if (cmatrix[i][j] == -1)
            {
                dfs(i, j, r, c, clr, matrix[i][j]);
                clr++;
            }
        }
    }
    i64 n;
    cin >> n;

    for (i64 i = 0; i < n; i++)
    {
        i64 r1, c1;
        i64 r2, c2;

        cin >> r1 >> c1 >> r2 >> c2;

        r1--;
        c1--;
        r2--;
        c2--;

        if (cmatrix[r1][c1] == cmatrix[r2][c2])
        {
            if (matrix[r1][c1] == matrix[r2][c2])
            {
                if (matrix[r1][c1] == 0)
                {
                    cout << "binary" << endl;
                }

                else
                {
                    cout << "decimal" << endl;
                }
            }
        }
        else
        {
            cout << "neither" << endl;
        }
    }

    return 0;
}