#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 l, r, x;
    cin >> l >> r;

    if(l > r)
    {
        x = l * 2;
        cout << "Odd " << x << endl;
    }
    if(r > l)
    {
        x = r * 2;
        cout << "Odd " << x << endl;
    }
    if(l == r && l != 0 && r != 0)
    {
        x = r * 2;
        cout << "Even " << x << endl;
    }
    if(l == 0 && r == 0)
    {
        cout << "Not a moose" << endl;
    }
}