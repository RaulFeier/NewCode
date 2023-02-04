#include <iostream>
#include <string>

using namespace std;
#define endl '\n'
using i64 = long long;

bool check(i64, i64, i64);

int main()
{
    i64 n;
    cin >> n;
    cout << n << ":" << endl;

    for (i64 i = 2; i <= (n / 2) + 1; i++)
    {
        for (i64 j = i - 1; j < i + 1; j++)
        {
            if (check(i, j, n) == true)
            {
                cout << i << "," << j << endl;
            }
        }
    }

    return 0;
}

bool check(i64 i, i64 j, i64 n)
{
    i64 sum = 0, k = 0;

    if (i + j == n)
    {
        return true;
    }

    while (sum < n)
    {
        if (k % 2 == 0)
        {
            sum += i;
        }
        else
        {
            sum += j;
        }
        k++;
    }
    
    if (sum == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
