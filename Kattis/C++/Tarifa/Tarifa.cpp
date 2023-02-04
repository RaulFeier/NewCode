#include <iostream>

using namespace std;
using i64 = long long;

int main() 
{
    i64 megabytes = 0;
    i64 months = 0;

    cin >> megabytes >> months;

    int used = 0;
    for(i64 i = 0;i < months;i++) 
    {
        i64 temp;

        cin >> temp;
        used += temp;
    }

    cout << megabytes * (months + 1) - used << endl;
}
