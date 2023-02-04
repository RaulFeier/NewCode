#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 n, sum = 0;
    cin >> n;
    
    for(i64 i = 0;i < n;i++)
    {
        i64 x;
        cin >> x;
        if(x < 0)
        {
            sum += x * -1;
        }
    }

    cout << sum << endl;
    
    return 0;
}