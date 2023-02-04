#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 b, k;
    d6 g, t;

    cin >> b >> k >> g;
    
    t = floor(k / g);
    b = b - 1;

    cout << ceil(b / t);
}