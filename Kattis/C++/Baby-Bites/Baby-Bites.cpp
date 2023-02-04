#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 n;

    cin >> n;

    cin.ignore();
    for(i64 i = 1;i <= n;i++)
    {
        string m;
        cin >> m;
        if(m == "mumble")
        {
            continue; 
        }
        if(to_string(i) != m)
        {
            cout << "something is fishy" << endl;
            return 0;
        }
    }
    cout << "makes sense" << endl;
    return 0;
}