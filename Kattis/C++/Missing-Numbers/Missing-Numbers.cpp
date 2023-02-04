#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 n, z = 0;
    cin >> n;

    i64 a = 1, x;
    while(n-- > 0)
    {
        cin >> x;
        for(i64 i = a;i < x;i++)
        {
            cout << i << endl;
            z = 1;
        }
        a = x + 1;
    }
    if(z == 0)
    {
        cout << "good job" << endl;
    }

    return 0;
}