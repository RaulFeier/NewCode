#include <iostream>

using namespace ::std;

int main()
{
    int k, m, n;

    cin >> k >> m >> n;

    if (k % (m + n) < m)
    {
        cout << "Barb" << endl;
    }
    else
    {
        cout << "Alex" << endl;
    }
    
    return 0;
}