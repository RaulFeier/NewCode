#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    i64 factorial = 1;

    for (i64 i = 1;i <= 999;i++)
    {
        factorial *= i;
    }

    cout << factorial << endl;
}