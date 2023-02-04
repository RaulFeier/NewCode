#include <bits/stdc++.h>

using namespace std;
typedef int64_t i64;

int main()
{
    i64 n, start = 0, end = 0;
    i64 temp = 0;

    cin >> n;

    bool t = false;

    while(n--)
    {
        i64 a;

        cin >> a;
        t = !t;

        if(t)
        {
            start = a;
        }
        else
        {
            end = a;
            temp += end - start;
        }
    }

    if(t) 
    {
        cout << "still running\n";
    }
    else
    {
        cout << temp << "\n";
    }
}