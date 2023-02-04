#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int checker(int n)
{
    i64 s = 0;
    while(n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main()
{
    i64 a,b,x,n,m;

    cin >> a >> b >> x;
    
    n = a;
    m = b;
    
    while(checker(n) != x)
    {
        n++;
    }
    while(checker(m) != x)
    {
        m--;
    }

    cout << n << endl << m << endl;
    return 0;
}