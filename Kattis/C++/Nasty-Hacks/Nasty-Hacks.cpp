#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;
using s = string;

int main()
{
    i64 a, b, c, n;
    cin >> n;
    
    for(i64 i = 0;i < n;i++)
    {
        cin >> a >> b >> c;
        if(b - c > a)
        {
            cout << "advertise" << endl;
        }
        else if(b - c == a)
        {
            cout << "does not matter" << endl;
        }
        else
        {
            cout << "do not advertise" << endl;
        }
    }

}