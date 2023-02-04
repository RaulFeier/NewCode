#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 digit_sum(i64 x) 
{
    
    i64 res = 0;
    while (x > 0) 
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}

i64 total_sum(i64 x) 
{
    i64 d = x % 10;
    return x == 0 ? 0 : d * (d - 1) / 2 + d * digit_sum(x / 10) + 10 * total_sum(x / 10) + (x / 10) * 45;
}

int main() 
{

    i64 runs;
    cin >> runs;

    while (runs--) 
    { 
        i64 lo, hi;
        cin >> lo >> hi;
        cout << total_sum(hi + 1) - total_sum(lo) << endl;
    }

    return 0;
}