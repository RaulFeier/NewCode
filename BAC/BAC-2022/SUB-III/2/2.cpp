#include <bits/stdc++.h>

using namespace std;

typedef int64_t i64;

i64 m, n;
i64 arr[100][100];

bool checker(i64 i, i64 j, vector<i64> &v)
{
    bool res = true;

    if (count(v.begin(), v.end(), 1))
    {
        if (!(arr[i][j - 1] > arr[i][j]))
        {
            res = false;
        }
    }
    if (count(v.begin(), v.end(), 2))
    {
        if (!(arr[i - 1][j] > arr[i][j]))
        {
            res = false;
        }
    }
    if (count(v.begin(), v.end(), 3))
    {
        if (!(arr[i][j + 1] > arr[i][j]))
        {
            res = false;
        }
    }
    if (count(v.begin(), v.end(), 4))
    {
        if (!(arr[i + 1][j] > arr[i][j]))
        {
            res = false;
        }
    }

    return res;
}

int main()
{
    cin >> m >> n;
    bool used[m][n];
    for (i64 i = 0; i < m; i++)
    {
        for (i64 j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            used[i][j] = false;
        }
    }

    i64 res = 0;
    for (i64 i = 0; i < m; i++)
    {
        for (i64 j = 0; j < n; j++)
        {
            if (used[i][j])
            {
                continue;
            }

            vector<i64> v1;
            if (j - 1 < 0)
            {
                v1.push_back(1);
            }
            if (i - 1 < 0)
            {
                v1.push_back(2);
            }
            if (j + 1 >= m)
            {
                v1.push_back(3);
            }
            if (i + 1 >= n)
            {
                v1.push_back(4);
            }
            v1.push_back(3);

            vector<i64> v2;
            if (i - 1 < 0 && j + 1 >= n)
            {
                v2.push_back(2);
            }
            if (j + 2 >= m)
            {
                v2.push_back(3);
            }
            if (i + 1 >= n && j + 1 >= m)
            {
                v2.push_back(4);
            }
            v2.push_back(1);

            if (checker(i, j, v1) && checker(i, j + 1, v2))
            {
                res += abs(arr[i][j] - arr[i][j + 1]);
            }
        }
    }

    cout << res << endl;

    return 0;
}

// NU MEIE