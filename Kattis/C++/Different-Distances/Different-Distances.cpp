#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    d6 x1,x2,y1,y2,p;
    cout.precision(8);
    
    while(cin >> x1 && cin >> y1 && cin >> x2 && cin >> y2 && cin >> p)
    {
        d6 x = pow(abs(x1 - x2), p);
        d6 y = pow(abs(y1 - y2), p);
        cout << fixed << pow(x + y, (1 / p)) << endl;
    }
}