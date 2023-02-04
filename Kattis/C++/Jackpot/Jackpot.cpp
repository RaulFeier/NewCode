#include <bits/stdc++.h>

using namespace std;
typedef int64_t i64;

int main() {
    i64 n;
    cin >> n;

    for(i64 i = 0;i < n;i++)
    {
        i64 a = 1;
        i64 b;
        cin >> b;

        for(i64 c = 0;c < b;c++)
        {
            i64 d;
            cin >> d;

            if(a <= 1e9 && a >= 0)
            {
                i64 e = a;
                i64 m = min(d, e);
                i64 n = max(d, e);
                
                while (m!=0)
                {
                    i64 temp = n % m;
                    n = m;
                    m = temp;
                }
                a = d / n * a;
            }
        }
        if (a > 1e9 || a <= 0)
        {
            cout << "More than a billion.\n";
        }
        else
        {
            cout << a << endl;
        }
    }
}