#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;
using s = string;

int main()
{
    i64 n;
    cin >> n;
    
    for(i64 i = 0;i < n;i++)
    {
        i64 m = 1;
        i64 s = 0;
        i64 x;
        while(true)
        {
            cin >> x;
            
            if(x == 0)
            {
                break;
            }
            if(x > 2 * m)
            {
                s += x - 2 * m;
            }
            m = x;
        }
        cout << s << endl;        
    }
}