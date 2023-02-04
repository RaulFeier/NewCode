#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    i64 g, s, c, p;

    cin >> g >> s >> c;

    p = 3 * g + 2 * s + c;

    if(p >= 8)
    {
        cout << "Province" << " or ";
    }
    else if(p >= 5)
    {
        cout << "Duchy" << " or ";
    }
    else if(p >= 2)
    {
        cout << "Estate" << " or ";
    }
    else if(p < 0)
    {
        cout << "Copper" << endl;
    }
    if(p >= 6)
    {
        cout << "Gold" << endl;
    }
    else if(p >= 3)
    {
        cout << "Silver" << endl;
    }
    else if(p >= 0)
    {
        cout << "Copper" << endl;
    }

    return 0;
}