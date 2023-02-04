#include <iostream>
#include <string>

using namespace ::std;

typedef long long ll;

int main()
{
    char prevPos;
    string positions;
    int n, counter = 0;
    cin >> positions;
    n = positions.length();

    // case1
    counter = 0;
    for (int i = 2; i < n; i++)
    {
        if (positions[i] == 'D')
        {
            counter += 2;
        }
    }
    if (positions[0] != positions[1])
    {
        counter += 1;
    }
    if (positions[1] != 'U')
    {
        counter += 1;
    }

    cout << counter << endl;

    // case2
    counter = 0;
    for (int i = 2; i < n; i++)
    {
        if (positions[i] == 'U')
        {
            counter += 2;
        }
    }
    if (positions[0] != positions[1])
    {
        counter += 1;
    }
    if (positions[1] != 'D')
    {
        counter += 1;
    }

    cout << counter << endl;

    // case3
    counter = 0;
    for (int i = 1; i < n; i++)
    {
        if (positions[i - 1] != positions[i])
        {
            counter += 1;
        }
    }

    cout << counter << endl;
    return 0;
}