#include <bits/stdc++.h>


using namespace std;
typedef long long i64;

int main()
{
    i64 n,t;

    cin >> n >> t;

    vector<i64> v(n);

    for(auto& i : v)
    {
        cin >> i;
    }

    if(t == 1)
    {
        cout << 7 << endl;
    }

    else if(t == 2)
    {
        if(v[0] > v[1])
        {
            cout << "Bigger" << endl;
        }
        else if(v[0] == v[1])
        {
            cout << "Equal" << endl;
        }
        else
        {
            cout << "Smaller" << endl;
        }
    }

    else if(t == 3)
    {
        sort(v.begin(),v.begin() + 3);
        cout << v[1] << endl;
    }

    else if(t == 4)
    {
        i64 m = 0;
        for(auto& i : v)
        {
            m += i;
        }
        cout << m << endl;
    }

    else if(t == 5)
    {
        i64 m = 0;
        for(auto& i : v)
        {
            if(i % 2 == 0)
            {
                m += i;
            }
        }
        cout << m << endl;
    }

    else if(t == 6)
    {
        for(auto& i : v)
        {
            i = i % 26;
            cout << char('a' + i);
        }
        cout << endl;
    }

    else if(t == 7)
    {
        i64 z = 0, c = 0;
        while(z < 999999)
        {
            z++;
            c = v[c];
            if(c > n - 1)
            {
                cout << "Out" << endl;
                return 0;
            }
            else if(c == n - 1)
            {
                cout << "Done" << endl;
                return 0;
            }
        }
        cout << "Cyclic" << endl;
    }
    return 0;
}
