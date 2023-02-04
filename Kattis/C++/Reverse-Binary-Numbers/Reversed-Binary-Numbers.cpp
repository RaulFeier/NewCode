#include <iostream>

using namespace std;
typedef int64_t i64;

int main()
{
    i64 n, z = 0;
    cin >> n;

    while(n > 0)
    {
        z = z * 2 + n % 2;
        n /= 2;
    }
    cout << z << endl;
}
