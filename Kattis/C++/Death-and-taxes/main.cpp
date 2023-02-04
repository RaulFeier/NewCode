#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector<string> split(string s)
{
    vector<string> ret = {""};
    for (auto i : s)
    {
        if (i == ' ')
        {
            ret.pb("");
        }
        else
        {
            ret.back().pb(i);
        }
    }
    return ret;
}

int main()
{
    // file();
    // fast();

    int count = 0;
    double val = 1;

    string s;
    while (getline(cin, s))
    {
        vector<string> v = split(s);
        if (v[0] == "buy")
        {
            int shares = stoi(v[1]);
            int price = stoi(v[2]);
            double newavg = (count * val) + (shares * price);
            newavg /= (count + shares);
            val = newavg;
            count += shares;
        }
        if (v[0] == "sell")
        {
            int shares = stoi(v[1]);
            int price = stoi(v[2]);
            count -= shares;
        }
        if (v[0] == "split")
        {
            int split = stoi(v[1]);
            count *= split;
            val /= split;
        }
        if (v[0] == "merge")
        {
            int split = stoi(v[1]);
            count /= split;
            val *= split;
        }
        if (v[0] == "die")
        {
            double price = stoi(v[1]);
            cout << fixed;
            cout.precision(3);

            cout << count * (price - (max(price - val, 0.0) * .3)) << endl;
        }
    }

    return 0;
}