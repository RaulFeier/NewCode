#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

vector<string> h;
vector<bool> used;
i64 rest = 1e9;

void solved(i64 pos, i64 n, i64 cos, vector<i64> &sol)
{
    if (pos == n)
    {
        rest = cos;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            sol.push_back(i);
            int ch = 0;
            if (pos > 0)
            {
                for (auto c1 : h[sol[pos]])
                {
                    for (auto c2 : h[sol[pos - 1]])
                    {
                        if (c1 == c2)
                        {
                            ch++;
                        }
                    }
                }
            }
            if (cos + ch < rest)
            {
                solved(pos + 1, n, cos + ch, sol);
            }
            
            sol.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    i64 n;
    cin >> n;

    for (i64 i = 0; i < n; i++)
    {
        string ans;

        cin >> ans;

        h.push_back(ans);
        used.push_back(false);
    }

    vector<i64> sol;

    solved(0, n, 0, sol);
    cout << rest << endl;
}
