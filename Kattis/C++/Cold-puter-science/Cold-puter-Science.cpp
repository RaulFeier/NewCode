#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    i64 n;
    cin >> n;
    i64 ans = 0;
    vector<i64> a(n);
    for (i64 i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] < 0)
        {
            ans++;
        }
    }

    cout << ans << endl;
}