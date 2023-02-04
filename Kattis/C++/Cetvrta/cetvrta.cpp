#include <iostream>
using namespace ::std;

int main()
{
    int x1, x2, x3, x4 = 0, y1, y2, y3, y4 = 0;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    if (x1 == x2 && x2 != x3)
    {
        x4 = x3;
    }
    if (y1 == y2 && y2 != y3)
    {
        y4 = y3;
    }
    if (x2 == x3 && x1 != x2)
    {
        x4 = x1;
    }
    if (y2 == y3 && y1 != y2)
    {
        y4 = y1;
    }
    if (x1 == x3 && x2 != x3)
    {
        x4 = x2;
    }
    if (y1 == y3 && y2 != y3)
    {
        y4 = y2;
    }
    
    cout << x4 << " " << y4 << endl;
    
    return 0;
}