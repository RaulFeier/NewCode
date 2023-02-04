#include <iostream>

using namespace std;
typedef int64_t i64;

int main()
{
    i64 n, v[100000];
    cin >> n;

    for(i64 i = 0;i < n;i++)
    {
        i64 a;
        cin >> a;
        long double total = 0.0;

        for(i64 i = 0;i < a;i++)
        {
            cin >> v[i];
            total += v[i];
        }
        
        total /= a;
        long double t=0.0;

        for(i64 i = 0;i < a;i++){
            if(v[i] > total)
            {
                t++;
            }
        }

        long double m = (t / a) * 100;
        cout.precision(3);
        cout << fixed;
        cout << m << "%" << "\n";
    }
}