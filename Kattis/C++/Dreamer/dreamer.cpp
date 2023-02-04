#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

i64 zile[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool date(i64 ziua, i64 luna, i64 an)
{
    if (an < 2000 || luna > 12 || luna == 0 || ziua == 0)
    {
        return false;
    }
    
    zile[1] = (an % 400 == 0 || (an % 4 == 0 && an % 100 != 0)) ? 29 : 28;
    if (zile[luna - 1] < ziua)
    {
        return false;
    }
    return true;
}

int main()
{

    string ans;
    getline(cin, ans);
    i64 n = stoi(ans);

    while (n--)
    {
        getline(cin, ans);

        ans.erase(remove(ans.begin(), ans.end(), ' '), ans.end());
        sort(ans.begin(), ans.end());

        i64 t = 0;

        vector<i64> anu_meu{32, 13, 10000};

        do
        {
            string ziua1;
            string luna1;
            string an1;
            for(i64 i = 0;i < 2;i++)
            {
                ziua1[i] = ans[i];
            }
            for(i64 i = 2;i < 4;i++)
            {
                luna1[i - 2] = ans[i];
            }
            for(i64 i = 4;i < 8;i++)
            {
                an1[i - 4] = ans[i];
            }

            i64 ziua = stoi(ziua1);
            i64 luna = stoi(luna1);
            i64 an = stoi(an1);

            if (date(ziua, luna, an))
            {
                t++;
                if (an < anu_meu[2] || (an == anu_meu[2] && luna < anu_meu[1]) || (an == anu_meu[2] && luna == anu_meu[1] && ziua < anu_meu[0]))
                {
                    anu_meu[0] = ziua;
                    anu_meu[1] = luna;
                    anu_meu[2] = an;
                }
            }

        } while (next_permutation(ans.begin(), ans.end()));

        cout << t << " ";
        
        if (anu_meu[2] < 10000)
        {
            if(anu_meu[0] < 10)
            {
                cout << "0" << anu_meu[0] << " ";
            }
            else
            {
                cout << anu_meu[0] << " ";
            }
            if(anu_meu[1] < 10)
            {
                cout << "0" << anu_meu[1] << " ";
            }
            else
            {
                cout << anu_meu[1] << " ";
            }
            cout << anu_meu[2] << endl;
        }
        cout << endl;
    }

    return 0;
}