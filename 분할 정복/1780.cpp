#include <iostream>

using namespace std;
int cnt[3];
int matrix[2187][2187];

void paper(int x, int y, int n)
{
    int num = matrix[x][y];
    bool same = true;

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (num != matrix[i][j])
            {
                same = false;
                break;
            }
        }
    }

    if (same)
    {
        cnt[num + 1]++;
    }
    else
    {
        int d = n / 3;
        paper(x, y, n / 3);
        paper(x + d, y, n / 3);
        paper(x + 2 * d, y, n / 3);

        paper(x, y + d, n / 3);
        paper(x + d, y + d, n / 3);
        paper(x + 2 * d, y + d, n / 3);

        paper(x, y + 2 * d, n / 3);
        paper(x + d, y + 2 * d, n / 3);
        paper(x + 2 * d, y + 2 * d, n / 3);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    paper(0, 0, n);

    cout << cnt[0] << '\n'
         << cnt[1] << '\n'
         << cnt[2];
}