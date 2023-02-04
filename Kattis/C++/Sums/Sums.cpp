#include <bits/stdc++.h>

using namespace std;
typedef int64_t i64;

void print(i64 n, i64 t, i64 a)
{
    cout << n << " = ";
    for (i64 i = 0; i < a; i++)
    {
        cout << t + i;
        if (i != a - 1)
            cout << " + ";
    }
    cout << endl;
}
void solve()
{
    i64 n;
    cin >> n;

    i64 a = 2;
    while (true)
    {
        i64 c = a * (a - 1) / 2; // sub=c temp=d

        i64 d = n - c;
        if (d <= 0)
            break;

        if (d % a == 0)
        {
            print(n, d / a, a);
            return;
        }

        a++;
    }

    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        solve();
    }
}