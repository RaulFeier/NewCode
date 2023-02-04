#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

int main()
{
    string line;
    
    while (getline(cin, line))
    {
        if (line == "END")
            break;
        if (line == "1")
        {
            cout << 1 << endl;
            continue;
        }
    
        int curr = line.size();
        int i = 2;
    
        while (1)
        {
            int next = 0;
            int temp = curr;
    
            while (temp > 0)
            {
                temp /= 10;
                next++;
            }
    
            if (curr == next)
            {
                cout << i << endl;
                break;
            }
    
            i++;
            curr = next;
        }
    }
}
