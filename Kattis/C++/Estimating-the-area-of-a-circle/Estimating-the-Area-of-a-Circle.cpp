#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    d6 n,a,b;
    cin >> n >> a >> b;
    while(n != 0 || a != 0 || b != 0)
    {
        d6 res = (b * n * n * 4) / a;
        cout.precision(10);
        cout << n * n * M_PI << " " << res << endl;
        cin >> n >> a >> b;
    }
    return 0;
}