#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 n, w, h;

    cin >> n >> w >> h;
    d6 d = sqrt(w * w + h * h);

    for(i64 i = 0;i < n;i++)
    {
        i64 x;
        cin >> x;
        if (x <= d)
        {
            cout << "DA\n";
        }
        else
        {
            cout << "NE\n";
        }
    }
}