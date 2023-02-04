#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 n;
    cin >> n;

    for(i64 i = 0;i < n;i++)
    {
        string ans;
        cin >> ans;

        i64 a = sqrt(ans.length());

        char m[a][a]; 

        i64 t = 0;
        for(i64 j = 0;j < a;j++)
        {
            for(i64 k = 0;k < a;k++)
            {
                m[j][k] = ans[t];
                t++;
            }
        }

        for(i64 k = a - 1;k >= 0;k--)
        {
            for(i64 j = 0;j < a;j++)
            {
                cout << m[j][k];
            }
        }
        cout << endl;

    }
}