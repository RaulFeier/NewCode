#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    string ans;
    cin >> ans;


    for (i64 i = 0; i < ans.size(); i++)
    {
        if (ans[i] == 'a')
        {
            i64 k = i;
            for (i64 j = k;j < ans.size();j++)
            {
                cout << ans[j];
            }
            cout << endl;
            return 0;
        }
    }
}