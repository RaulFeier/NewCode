#include <iostream>

using namespace std;
typedef int64_t i64;
int main()
{
    i64 v[100000], n;
    cin >> n;
    
    for (i64 i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (i64 i = n - 1; i >= 0; i--)
    {
        cout << v[i] << endl;
    }

    return 0;
}
