#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 t;
    cin >> t;
    
    for(i64 i = 0;i < t;i++)
    {
        i64 n;
        cin >> n;
        i64 total = 1;
        for(i64 j = 1;j <= n;j++)
        {
            total *= j;
        }
        cout << total % 10 << endl;
    }
}