#include <iostream>

using namespace ::std;

int main() 
{
    int n, d;
    cin >> n >> d;
    bool yes = false;

    for (int i = 0; i < n; ++i) 
    {
        int dOfM;
        cin >> dOfM;
        if (dOfM <= d) 
        {
            yes = true;
            cout << "It hadn't snowed this early in " << i << " years!\n";
            break;
        }
    }
    if (!yes) 
    {
        cout << "It had never snowed this early!\n";
    }
    return 0;
}