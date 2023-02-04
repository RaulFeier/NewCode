#include <bits/stdc++.h>
#define VMULT (long long)1e18
#define MULT (long long)1e9


using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    string x;
    cin >> x;
    i64 xn = stoi(x);
    sort(x.begin(), x.end());
    i64 sm = MULT;

    do
    {
        i64 xp = stoi(x);
        if (xp > xn and xp < sm)
        {
            sm = xp;
        }
    } while (next_permutation(x.begin(), x.end()));
    
    i64 ans = sm != MULT ? sm : 0;

    cout << ans << endl;
    return 0;
}