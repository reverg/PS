#include <iostream>

using namespace std;
int cnt[2];
int blue[128][128];

void paper(int x, int y, int n)
{
    int color = blue[x][y];
    bool same = true;

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (color != blue[i][j])
            {
                same = false;
                break;
            }
        }
    }

    if (same)
    {
        cnt[color]++;
    }
    else
    {
        paper(x, y, n / 2);
        paper(x + n / 2, y, n / 2);
        paper(x, y + n / 2, n / 2);
        paper(x + n / 2, y + n / 2, n / 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> blue[i][j];

    paper(0, 0, n);

    cout << cnt[0] << '\n'
         << cnt[1];
}