#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    i64 a,b,c,m;
    cin >> m >> a >> b >> c;

    if((a + b + c) / 2 <= m)
    {
        cout << "possible" << endl;
    }
    else
    {
        cout << "impossible" << endl;
    }
}