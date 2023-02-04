#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d64 = double long;

int main()
{
    i64 a, b, c;
    cin >> a >> b >> c;
    i64 i, j, k;
    cin >> i >> j >> k;

    d64 c1 = 1.0 * a / i;
    d64 c2 = 1.0 * b / j;
    d64 c3 = 1.0 * c / k;
    d64 q = min({c1, c2, c3});
 
    cout << fixed << setprecision(6);
    cout << a - q * i << " ";
    cout << b - q * j << " ";
    cout << c - q * k << endl;
}