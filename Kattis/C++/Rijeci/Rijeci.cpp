#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    i64 k;

    cin >> k;
    i64 a = 1, b = 0;

    for(i64 i = 0;i < k;i++)
    {
        i64 m, n;
        m = b;
        n = a + b;
        a = m;
        b = n;
    }

    cout << a << " " << b << endl;
}