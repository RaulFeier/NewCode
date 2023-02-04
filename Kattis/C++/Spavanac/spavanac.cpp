#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 h, m;
    cin >> h >> m;

    if(m >= 45)
    {
        m -= 45;
    }
    else
    {
        m += 15;
        h -= 1;
    }
    
    if(h < 0)
    {
        h += 24;
    }

    cout << h << " " << m << endl;
    return 0;
}