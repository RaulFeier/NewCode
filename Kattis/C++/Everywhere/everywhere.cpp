#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 n;
    cin >> n;

    for (i64 i = 0; i < n; i++)
    {
        i64 m;
        cin >> m;
        set<string> v;

        for (i64 j = 0; j < m; j++)
        {
            string ans;
            cin >> ans;
            v.insert(ans);
        }

        cout << v.size() << endl;
    }
}
