#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 n,a = 0;
    cin >> n;
    for(i64 i = 0;i < n;i++)
    {
        i64 t1,d1,t2,d2;
        cin >> t1 >> d1;
        if(((d1 - d2) / (t1 - t2)) > a)
        {
            a = (d1 - d2) / (t1 - t2);
        }
        t2 = t1;
        d2 = d1;
    }
    cout << a << endl;

}