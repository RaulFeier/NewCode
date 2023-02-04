#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int i, j, k;
    int m, p, l, e, r, s, n;
    int temp;

    while (cin >> m)
    {
        cin >> p >> l >> e >> r >> s >> n;
        for (i = 0; i < n; i++)
        {
            temp = m;
            m = p / s;
            p = l / r;
            l = temp * e;
        }

        cout << m << "\n";
    }

}