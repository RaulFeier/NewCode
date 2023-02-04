#include <bits/stdc++.h>

using namespace std;

int main()
{

    std::ios_base::sync_with_stdio(false);

    int n;
    int tc = 0;
    while (cin >> n, n)
    {
        vector<string> v;
        string s;
        if (tc++)
            cout << endl;
        while (n--)
        {
            cin >> s;
            v.push_back(s);
        }

        stable_sort(v.begin(), v.end(), [](string a, string b)
        {
			if (a[0] == b[0]) 
            {
				if (a[1] == b[1]) 
                {
					return false;
				} 
                else 
                {
					return a[1] < b[1];
				}
			}
			return a[0] < b[0]; 
        });

        for (auto i : v)
        {
            cout << i << endl;
        }
    }

    return 0;
}