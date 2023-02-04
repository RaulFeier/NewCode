#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
typedef int64_t i64;
using d6 = long double;

int main()
{
    i64 n, p;
    cin >> n;
    i64 v[n];
    v[0] = 1;

    for (i64 i = 2; i <= n; i++)
    {
        cin >> p;
        v[p + 1] = i;
    }
    for (auto i : v)
    {
        cout << i << " ";
    }

    cout << endl;
}