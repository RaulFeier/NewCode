#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int parent(int i, vector<i64> &u)
{
    int ii = i;
    int p = u[i];
    while (p != i)
    {
        i = p;
        p = u[i];
    }
    if (u[ii] != p)
    {
        u[ii] = p;
    }
    return p;
}

void join(int i, int j, vector<i64> &u, vector<i64> &r)
{
    int pi = parent(i, u);
    int pj = parent(j, u);
    if (pi != pj)
    {
        if (r[pi] >= r[pj])
        {
            u[pj] = pi;
            r[pi] += 1;
        }
        else
        {
            u[pi] = pj;
            r[pj] += 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    i64 n, q;
    cin >> n >> q;

    vector<i64> u(n);
    vector<i64> r(n);
    for (i64 i = 0; i < n; i++)
    {
        u[i] = i;
        r[i] = 1;
    }

    for (i64 i = 0; i < q; i++)
    {
        char h;
        i64 a, b;
        cin >> h >> a >> b;

        if (h == '=')
        {
            join(a, b, u, r);
        }
        if (h == '?')
        {
            if (parent(a, u) == parent(b, u))
            {
                cout << "yes" << '\n';
            }
            else
            {
                cout << "no" << '\n';
            }
        }
    }
}