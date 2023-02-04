#include <iostream>
#include <cmath>

using namespace::std;
using i64 = long long;


int main()
{
    i64 n, sum = 0, z;
    cin >> n;

    for(i64 i = 0;i < n; i++)
    {
        cin >> z;
        sum += z;
    }

    cout << sum << endl;


    return 0;
}
