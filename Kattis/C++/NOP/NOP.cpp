#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    string s;

    cin >> s;

    vector<char> v(10000);
    for(i64 i = 0;i < s.size();i++)
    {
        v[i] = s[i];
    }


    i64 t = 0;

    for(i64 i = 0;i < v.size();i++)
    {
        if(i % 4 != 0 && v[i] <= 'Z'  && v[i] >= 'A')
        {
            v.insert(v.begin() + i, 'n');
            i = 0;
            t++;
        }
    }

    cout << t << endl;

    return 0;  
}