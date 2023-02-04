#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    i64 x;

    cin >> x;

    i64 res = x;
    while (res > 9)
    {
        i64 crt = res;

        res = 1;
        while (crt > 0)
        {
            if (crt % 10 != 0)
            {
                res *= (crt % 10);
            }
            crt /= 10;
        }
    }
    
    cout << res << endl;
    return 0;
}
