#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 n;
    cin >> n;
    vector<bool> v(26, false);
    for (i64 i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        if (a == 'T')
        {
            v[i] = true;
        }
    }

    char masa;
    vector<bool> v1;
    while (cin >> masa)
    {
        if (masa >= 'A' && masa <= 'Z')
        {
            v1.push_back(v[masa - 'A']);
        }
        else if (masa == '+')
        {
            bool b1 = v1.back();
            v1.pop_back();
            bool b2 = v1.back();
            v1.pop_back();
            v1.push_back(b1 || b2);
        }
        else if (masa == '*')
        {
            bool b1 = v1.back();
            v1.pop_back();
            bool b2 = v1.back();
            v1.pop_back();
            v1.push_back(b1 && b2);
        }
        else
        {
            bool b1 = v1.back();
            v1.pop_back();
            v1.push_back(!b1);
        }
    }

    if (v1.back() == true)
    {
        cout << 'T' << endl;
    }
    else
    {
        cout << 'F' << endl;
    }
}