#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;
using s = string;

int main()
{
    i64 n;
    cin >> n;
    vector<i64> v(n);
    vector<i64> a(n,0);
    for(i64 i = 0;i < n;i++)
    {
        cin >> v[i];
        a[v[i] - 1]++;
    }
    for(i64 i = 5;i >= 0;i--)
    {
        if(a[i] == 1)
        {
            for(i64 j = 0;j < n;j++)
            {
                if(v[j] == i + 1)
                {
                    cout << j+1;
                }
            }
            return 0;
        }
    }
    cout << "none" << endl;
}