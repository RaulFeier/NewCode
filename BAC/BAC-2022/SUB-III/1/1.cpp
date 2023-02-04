#include <iostream>

using namespace std;

typedef int64_t i64;

i64 secventa(i64 n)
{
    i64 arr[9];
    i64 i = 0;

    while (n)
    {
        arr[i++] = n % 10;
        n /= 10;
    }

    for (i64 j = i; j > 0; j--)
    {
        if (arr[j] == 2 && arr[j - 1] == 2)
        {
            arr[j - 1] = 0;
        }
    }

    while (i--)
    {
        n *= 10;
        n += arr[i];
    }

    return n;
}

int main()
{
    i64 n;
    cin >> n;
    cout << secventa(n) << endl;

    return 0;
}