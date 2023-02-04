#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    i64 x,y;
    cin >> x >> y;
    
    while(x != 0 || y != 0)
    {
        if (x + y == 13)
        {
            cout << "Never speak again." << endl;
        }
        else if(x > y)
        {
            cout << "To the convention." << endl;
        }
        else if(x == y)
        {
            cout << "Undecided." << endl;
        }
        else
        {
            cout << "Left beehind." << endl;
        }
        cin >> x >> y;
    }
    return 0;
}
