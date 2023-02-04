#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 n, m;
    cin >> n >> m;
    vector<i64> v(n);
    for (i64 i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (m == 1)
    {
        i64 ans = 0;
        for (i64 i = 0; i < n; i++)
        {
            if (i + 3 < n)
            {
                if (v[i] == v[i + 1] && v[i + 1] == v[i + 2] && v[i + 2] == v[i + 3])
                {
                    ans++;
                }
            }
            ans++;
        }
        cout << ans << endl;
    }
    else if (m == 2)
    {
        i64 ans = 0;
        for (i64 i = 0; i < n; i++)
        {
            if (i + 1 < n)
            {
                if (v[i] == v[i + 1])
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    else if (m == 3)
    {
        i64 ans = 0;
        for (i64 i = 0; i < n; i++)
        {
            if (i + 2 < n)
            {
                if (v[i] == v[i + 1] && v[i + 1] == v[i + 2] - 1)
                {
                    ans++;
                }
            }
            if (i + 1 < n)
            {
                if (v[i] - 1 == v[i + 1])
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    else if (m == 4)
    {
        i64 ans = 0;
        for (i64 i = 0; i < n; i++)
        {
            if (i + 2 < n)
            {
                if (v[i] - 1 == v[i + 1] && v[i + 1] == v[i + 2])
                {
                    ans++;
                }
            }
            if (i + 1 < n)
            {
                if (v[i] == v[i + 1] - 1)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    else if (m == 5)
    {
        i64 ans = 0;
        for (i64 i = 0; i < n; i++)
        {
            if (i + 1 < n)
            {
                if (v[i] == v[i + 1] - 1)
                {
                    ans++;
                }
                if (v[i] - 1 == v[i + 1])
                {
                    ans++;
                }
            }
            if (i + 2 < n)
            {
                if (v[i] == v[i + 1] + 1 && v[i + 1] + 1 == v[i + 2])
                {
                    ans++;
                }
                if (v[i] == v[i + 1] && v[i + 1] == v[i + 2])
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    else if (m == 6)
    {
        i64 ans = 0;
        for (i64 i = 0; i < n; i++)
        {
            if (i + 1 < n)
            {
                if (v[i] == v[i + 1])
                {
                    ans++;
                }

                if (v[i] - 2 == v[i + 1])
                {
                    ans++;
                }
            }
            if (i + 2 < n)
            {
                if (v[i] == v[i + 1] && v[i + 1] == v[i + 2])
                {
                    ans++;
                }
            }
            if (i + 2 < n)
            {
                if (v[i] + 1 == v[i + 1] && v[i + 1] == v[i + 2])
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    else if (m == 7)
    {
        i64 ans = 0;
        for (i64 i = 0; i < n; i++)
        {
            if (i + 1 < n)
            {
                if (v[i] == v[i + 1])
                {
                    ans++;
                }
                if (v[i] == v[i + 1] - 2)
                {
                    ans++;
                }
            }
            if (i + 2 < n)
            {
                if (v[i] == v[i + 1] && v[i + 1] == v[i + 2])
                {
                    ans++;
                }
            }
            if (i + 2 < n)
            {
                if (v[i] == v[i + 1] && v[i] == v[i + 2] + 1)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}