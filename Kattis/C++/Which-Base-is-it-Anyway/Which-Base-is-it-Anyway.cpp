#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    i64 n;
    cin >> n;

    for(i64 i = 0; i < n; i++)
    {
        i64 x, y;
        cin >> x >> y;

        i64 a = y,c = y;
        i64 s = 0,p = 1;
        
        while(a != 0)
        {
            if(a % 10 < 8)
            {
                s += (a % 10) * p;
            }
            else
            {
                s = 0;
                break;

            }
            a /= 10;
            p *= 8;
        }
        cout << x << " " << s << " ";
        cout << y << " ";

        s = 0,p = 1;
        while( c != 0)
        {
            s += (c % 10) * p;
            c /= 10;
            p *= 16;
        }
        
        cout << s << endl;
    }
    return 0;
}