#include <iostream>
#include <cmath>

using namespace std;
typedef int64_t i64;

int main()
{
    i64 t, n;
    cin >> n;

    for (i64 i = 0; i < n; i++)
    {
        cin >> t;
        i64 a = 0, b = 0;

        if (t % 10 != 0)
        {
            a = t - 1;
            cout << a << "\n";
        }
        else
        {
            while (t % 10 == 0)
            {
                t /= 10;
                b++;
            }
            t -= 1;
            while (b-- > 0)
            {
                t *= 10;
            }
            cout << t << "\n";
        }
    }
}