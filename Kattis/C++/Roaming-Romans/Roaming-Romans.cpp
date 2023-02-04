#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    d6 n;
    cin >> n;
    i64 res = round((n * 5280000) / 4854.0);
    cout << res << endl;
    return 0;
}