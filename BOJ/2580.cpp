#include <iostream>

using namespace std;

bool col[10][10], row[10][10], sqr[10][10];
int ans[10][10];

bool fill(int k)
{
    if (k == 81)
        return true;

    int i = k % 9;
    int j = k / 9;

    if (ans[i][j] == 0)
    {
        for (int t = 1; t <= 9; t++)
        {
            if (!col[j][t] && !row[i][t] && !sqr[(i / 3) * 3 + (j / 3)][t])
            {
                col[j][t] = row[i][t] = sqr[(i / 3) * 3 + (j / 3)][t] = true;
                ans[i][j] = t;
                if (fill(k + 1))
                    return true;
                col[j][t] = row[i][t] = sqr[(i / 3) * 3 + (j / 3)][t] = false;
                ans[i][j] = 0;
            }
        }
    }
    else
    {
        return fill(k + 1);
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> ans[i][j];
            if (ans[i][j] != 0)
            {
                row[i][ans[i][j]] = col[j][ans[i][j]] = sqr[(i / 3) * 3 + (j / 3)][ans[i][j]] = true;
            }
        }
    }

    fill(0);
    cout << '\n';

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}