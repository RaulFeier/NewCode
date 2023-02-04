#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
typedef int64_t i64;
using d6 = long double;

int main()
{

    i64 a;
    cin >> a;

    for (i64 k = 0; k < a; k++)
    {
        i64 b;
        cin >> b;
        i64 v[b];
        
        for (i64 i = 0; i < b; i++)
        {
            cin >> v[i];
        }

        i64 r, g;
        for (i64 i = 0; i < b; i++)
        {
            g = 0;
            for (i64 j = 0; j < b; j++)
            {
                if (v[j] == v[i])
                {
                    g++;
                }
            }

            if (g != 2)
            {
                r = v[i];
                break;
            }
        }

        cout << "Case #" << k + 1 << ": " << r << endl;
    }
    return 0;
}