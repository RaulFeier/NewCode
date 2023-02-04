#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    i64 p, k, n;
    cin >> p;

    for(i64 i = 0;i < p;i++)
    {
        cout << fixed;
        cin >> k >> n;
        cout << k << " " << ((n * (n + 1)) / 2) << " " << i64 (pow(n, 2)) << " " << (n * (n + 1)) << endl;
    }

    return 0;
}