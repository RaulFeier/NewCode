#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 n, m, p;
    d6 a = 0, b = 0;
    cin >> n;

    for(i64 i = 0;i < n;i++)
    {
        cin >> m >> p;
        a += m;
        b += p;
    }

    d6 total = b / (a * 60);

    if(total <= 1)
    {
        cout << "measurement error" << endl;
    }
    else
    {
        cout << fixed << setprecision(9) << total << endl;
    }

    return 0;
}