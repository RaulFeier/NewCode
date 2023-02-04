#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 a,b,n = 0;
    cin >> a >> b;
    while(b % a != 0)
    {
        b++;
        n++;
    }
    for(i64 i = 0;i < (a - n);i++)
    {
        for(i64 j = 0;j < (b / a);j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    while(n > 0)
    {
        for(i64 i = 0;i < (b - 1) / a;i++)
        {
            cout << "*";
        }
        n--;
        cout << endl;
    }
    return 0;
}