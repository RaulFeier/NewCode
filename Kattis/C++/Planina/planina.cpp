#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 n;
    cin >> n;

    i64 p = 2;
    for(i64 i = 0;i < n;i++)
    {
        p *= 2;
        p -= 1;
    }

    cout << p * p << endl;
}