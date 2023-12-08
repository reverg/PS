#include <iostream>

using namespace std;

char sky[3072][6145];

void star(int len, int x, int y)
{
    if (len == 3)
    {
        sky[y][x] = '*';
        sky[y + 1][x - 1] = sky[y + 1][x + 1] = '*';
        sky[y + 2][x - 2] = sky[y + 2][x - 1] = sky[y + 2][x] = sky[y + 2][x + 1] = sky[y + 2][x + 2] = '*';
    }
    else
    {
        int hlen = len / 2;
        star(hlen, x, y);
        star(hlen, x - hlen, y + hlen);
        star(hlen, x + hlen, y + hlen);
    }
}

void print(int N)
{
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < 2 * N; i++)
        {
            printf("%c", sky[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    fill(&sky[0][0], &sky[3071][6144], ' ');

    star(N, N - 1, 0);

    print(N);
}