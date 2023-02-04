#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    i64 t;
    double n;
    cin >> t;

    for(i64 i = 0;i < t;i++)
    {
        cin >> n;
        cout << ceil(n / 400) << endl;
    }

    return 0;
}