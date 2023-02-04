#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 cases;
    cin >> cases;

    i64 n;
    for(i64 i = 0;i < cases;i++)
    {
        cin >> n;

        if(n % 2 == 0)
        {
            cout << n << " is even" << endl;
        }
        else
        {
            cout << n << " is odd" << endl;
        }
    }

    return 0;
}