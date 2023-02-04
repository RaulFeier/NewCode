#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 a, b, c, t = 0;
    cin >> a >> b >> c;

    i64 start = a + b;

    while(start >= c)
    {
        i64 zes = start / c;
        i64 pov = start % c;
        t += zes;
        start = pov + zes;
    }

    cout << t << endl;
}