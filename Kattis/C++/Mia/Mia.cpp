#include <iostream>

using namespace std;

int main()
{
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    while (a1 != 0)
    {
        int64_t p1 = max(a1, a2) * 10 + min(a1, a2);
        int64_t p2 = max(b1, b2) * 10 + min(b1, b2);

        if (p1 == 21 && p2 == 21)
        {
            cout << "Tie." << endl;
        }
        else if (p1 == 21)
        {
            cout << "Player 1 wins." << endl;
        }
        else if (p2 == 21)
        {
            cout << "Player 2 wins." << endl;
        }
        else if (p1 % 10 == p1 / 10 && p2 % 10 == p2 / 10)
        {
            if (p1 > p2)
            {
                cout << "Player 1 wins." << endl;
            }
            else if (p1 < p2)
            {
                cout << "Player 2 wins." << endl;
            }
            else
            {
                cout << "Tie." << endl;
            }
        }
        else if (p1 % 10 == p1 / 10)
        {
            cout << "Player 1 wins." << endl;
        }
        else if (p2 % 10 == p2 / 10)
        {
            cout << "Player 2 wins." << endl;
        }
        else if (p1 > p2)
        {
            cout << "Player 1 wins." << endl;
        }
        else if (p2 > p1)
        {
            cout << "Player 2 wins." << endl;
        }
        else
        {
            cout << "Tie." << endl;
        }

        cin >> a1 >> a2 >> b1 >> b2;
    }
}
