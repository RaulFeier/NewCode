#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a > 0 && b > 0 && c > 0 && a + b + c >= d && d >= 3)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}