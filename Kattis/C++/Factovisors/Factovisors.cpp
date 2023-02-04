#include <iostream>

using namespace std;

typedef int64_t i64;

int main()
{
    i64 n, m;
next:
    while (cin >> n)
    {
        cin >> m;
        if (m == 0)
        {
            cout << m << " does not divide " << n << "!" << endl;
            continue;
        }
        if (m == 1)
        {
            cout << m << " divides " << n << "!" << endl;
            continue;
        }
        if (m <= n)
        {
            cout << m << " divides " << n << "!" << endl;
            continue;
        }

        i64 x = m;
        i64 count = 0;

        for (i64 i = 2; i * i <= m; i++)
        {

            while (m % i == 0)
            {
                m /= i;
                count++;
            }

            if (count > 0)
            {

                for (i64 j = i; j <= n; j *= i)
                {
                    count -= n / j;
                }

                if (count > 0)
                {
                    cout << x << " does not divide " << n << "!" << endl;
                    goto next;
                }
            }

            count = 0;
        }

        if (m <= n)
        {
            cout << x << " divides " << n << "!" << endl;
        }
        else
        {
            cout << x << " does not divide " << n << "!" << endl;
        }
    }

    return 0;
}
