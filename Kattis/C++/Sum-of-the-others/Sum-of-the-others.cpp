#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    string s;

    while (getline(cin, s))
    {
        istringstream is(s);

        vector<i64> v;

        i64 sum = 0;
        i64 n;
        while (is >> n)
        {
            v.push_back(n);
            sum += n;
        }

        bool check = false;
        for (auto i : v)
        {
            if (sum - 2 * i == 0 && !check)
            {
                cout << i << endl;
                check = true;
            }
        }
    }

    return 0;
}