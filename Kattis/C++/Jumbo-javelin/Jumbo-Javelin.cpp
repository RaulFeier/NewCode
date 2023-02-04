#include <iostream>

using namespace std;
typedef int64_t i64;
int main()
{
    i64 n, l = 0;
    cin >> n;

    for (i64 i = 0; i < n; i++)
    {
        i64 v;
        cin >> v;
        
        l += v;
    }

    n = n - 1;
    cout << l - n << endl;

    return 0;
}
