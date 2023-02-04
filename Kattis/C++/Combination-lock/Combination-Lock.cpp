#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int cock(i64 n1, i64 n2)
{
    n1 += 40;
    n1 -= n2;
    n1 %= 40;
    return n1;
}

int cock2(i64 n1, i64 n2)
{
    n2 += 40;
    n2 -= n1;
    n2 %= 40;
    return n2;
}

int main()
{
    i64 n1, n2, n3, n4;

    while (cin >> n1 >> n2 >> n3 >> n4)
    {
        if (n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0)
        {
            break;
        }
        i64 ans = 120;

        ans += cock(n1, n2);
        ans += cock2(n2, n3);
        ans += cock(n3, n4);

        cout << ans * 9 << endl;
    }

    return 0;
}