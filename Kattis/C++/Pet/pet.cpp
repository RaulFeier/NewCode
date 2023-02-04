#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 w = 0, p = 0;

    i64 a,b,c,d;

    for(i64 i = 1;i <= 5;i++)
    {
        cin >> a >> b >> c >> d;
        if((a + b + c + d) > p)
        {
           w = i;
           p = a + b + c + d;
        }
    }

    cout << w << " " << p << endl;
}