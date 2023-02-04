#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    i64 n;
    string s;
    cin >> s >> n;

    if(s == "OCT" && n == 31)
    {
        cout << "yup" << endl;
    }
    else if(s == "DEC" && n == 25)
    {
        cout << "yup" << endl;
    }
    else
    {
        cout << "nope" << endl;
    }
}