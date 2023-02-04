#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    string a;
    getline(cin,a);
    
    vector<char> v(a.size());

    i64 t = 0;
    for(i64 i = 0;i < a.size();i++)
    {
        if(a[i] == 'a')
        {
            v[t] = a[i];
            i += 2;
        }
        else if(a[i] == 'e')
        {
            v[t] = a[i];
            i += 2;
        }
        else if(a[i] == 'i')
        {
            v[t] = a[i];
            i += 2;
        }
        else if(a[i] == 'o')
        {
            v[t] = a[i];
            i += 2;
        }
        else if(a[i] == 'u')
        {
            v[t] = a[i];
            i += 2;
        }
        else
        {
            v[t] = a[i];
        }
        t++;
    }

    for(i64 i = 0;i < v.size();i++)
    {
        cout << v[i];
    }
    cout << endl;
}