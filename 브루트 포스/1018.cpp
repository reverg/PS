#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    cin.get();

    int cnt = 64;
    char black[8][8];
    char white[8][8];

    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if ((i + j) % 2 == 0)
            {
                white[i][j] = 'W';
                black[i][j] = 'B';
            }

            else
            {
                white[i][j] = 'B';
                black[i][j] = 'W';
            }
        }
    }

    char pattern[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> pattern[i][j];
        }
    }

    for (int i = 0; i < N - 7; i++)
    {

        for (int j = 0; j < M - 7; j++)
        {
            int lcount1 = 0;
            int lcount2 = 0;
            for (int n = 0; n < 8; n++)
            {
                for (int m = 0; m < 8; m++)
                {
                    if (pattern[i + m][j + n] != black[m][n])
                        lcount1++;
                    else
                        lcount2++;
                }
            }
            if (((lcount1 > lcount2) ? lcount2 : lcount1) < cnt)
                cnt = ((lcount1 > lcount2) ? lcount2 : lcount1);
        }
    }

    cout << cnt;
    return 0;
}