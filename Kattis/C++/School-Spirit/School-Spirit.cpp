#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>

typedef long long i64;
using namespace std;
void fast()
{
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    i64 i, j, k;

    fast();
    
    i64 students;
    vector<i64> scores;

    cin >> students;
    i64 score;

    for (i = 0; i < students; i++)
    {
        cin >> score;
        scores.push_back(score);
    }

    sort(scores.rbegin(), scores.rend());

    double initialVal = 0;

    for (i = 0; i < students; i++)
    {
        initialVal += scores[i] * pow(4 / 5.0, i);
    }

    initialVal /= 5.0;

    double avg = 0;
    for (i = 0; i < students; i++)
    {
        double thisTot = 0;
        i64 used = 0;
        for (j = 0; j < students; j++)
        {
            if (i != j)
            {
                thisTot += scores[j] * pow(4 / 5.0, used);
                used++;
            }
        }
        
        thisTot /= 5.0;
        avg += thisTot;
    }

    avg /= students;

    cout << fixed << setprecision(10);
    cout << initialVal << "\n";
    cout << avg << "\n";
    return 0;
}