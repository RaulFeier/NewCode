#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string line;

    while (getline(cin, line))
    {
        stringstream ss;
        ss << line;
        int n;
        vector<int> v;
        while (ss >> n)
            v.push_back(n);

        sort(v.begin(), v.end());

        
        int occ[v.back()]; // say int occ[v.back()] = {0}; idk why vs-code error it but kattis accept it
        bool wrong = false;
        
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                wrong = wrong || occ[v[i] - v[j] - 1]++ > 0;
            }
        }

        if (wrong)
        {
            cout << "not a ruler" << endl;
            continue;
        }

        int counter = 0;
        for (int i = 0; i < v.back(); i++)
        {
            counter += occ[i];
        }

        if (counter == v.back())
        {
            cout << "perfect" << endl;
        }
        else
        {
            cout << "missing";
            for (int i = 0; i < v.back(); i++)
            {
                if (!occ[i])
                    cout << ' ' << i + 1;
            }
            cout << endl;
        }
    }

    return 0;
}