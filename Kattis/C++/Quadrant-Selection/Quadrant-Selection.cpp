#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 x,y;
    
    cin >> x >> y;

    if(x > 0 && y > 0)
    {
        cout << "1" << endl;
    }
    else if(x < 0 && y > 0)
    {
        cout << "2" << endl;
    }
    else if(x < 0 && y < 0)
    {
        cout << "3" << endl;
    }
    else if(x > 0 && y < 0)
    {
        cout << "4" << endl;
    }

    return 0;
}