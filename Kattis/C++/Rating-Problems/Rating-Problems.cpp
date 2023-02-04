#include <bits/stdc++.h>

using namespace std;
using d6 = long double;
using i64 = long long;

int main()
{
    i64 a,b;
    cin >> a >> b;
    
    d6 c,k = 0;
    for(i64 i = 0;i < b;i++)
    {
        cin >> c;
        k += c;
    }

    if(a == b)
    {
        cout << k / b << " " << k / b << endl;
    }
    else
    {
        d6 m1 = (a - b) * -3;

        m1 = m1 + k;
        m1 = m1 / a;
        
        cout << m1 << " ";

        d6 m2 = (a - b) * 3;

        m2 = m2 + k;
        m2 = m2 / a;

        cout << m2;
    }
    return 0;
}