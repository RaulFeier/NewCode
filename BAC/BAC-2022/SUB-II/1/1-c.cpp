#include <bits/stdc++.h>

using namespace std;
using i64 = long long;


int main()
{

    i64 n;
    cin >> n;
    i64 i = 2, k = 0;

    while (n >= i)
    {
        while (n % i == 0)
        {
            k++;
            n /= i;
        }
        if (i == 2)
        {
            i++;
        }
        else
        {
            i += 2;
        }
    }   

    cout << k << endl;

    return 0;
}