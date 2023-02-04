// project 7

#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int cmp[1000][1000];

int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};

void dfs(int r, int c, int x, int y, int col, int val)
{
    cmp[x][y] = col;

    for (int i = 0; i < 4; i++)
    {
        int xx = x + dirx[i];
        int yy = y + diry[i];

        if (xx >= 0 && yy >= 0 && xx < r && yy < c && t[xx][yy] == val && cmp[xx][yy] == -1)
        {
            dfs(r, c, xx, yy, col, val);
        }
    }
}
int main()
{
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char cr;
            cin >> cr;
            t[i][j] = cr - '0';
            cmp[i][j] = -1;
        }
    }

    int col = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (cmp[i][j] == -1)
            {
                dfs(r, c, i, j, col, t[i][j]);
                col += 1;
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << cmp[i][j] << " ";
        }
        cout << endl;
    }

}