#include <iostream>
#include <utility>

using namespace std;

int N, M, K;
int r, c;
bool notebook[40][40] = {false};
bool sticker[10][10];

bool try_paste(int y, int x)
{
    for (int j = 0; j < r; j++)
    {
        for (int i = 0; i < c; i++)
        {
            if (sticker[j][i] == 1 && notebook[y + j][x + i] == 1)
                return false;
        }
    }

    for (int j = 0; j < r; j++)
    {
        for (int i = 0; i < c; i++)
        {
            if (sticker[j][i] == 1)
                notebook[y + j][x + i] = 1;
        }
    }
    return true;
}

void rotate_sticker()
{
    bool tmp[10][10];

    for (int j = 0; j < r; j++)
        for (int i = 0; i < c; i++)
            tmp[j][i] = sticker[j][i];

    for (int j = 0; j < c; j++)
        for (int i = 0; i < r; i++)
            sticker[j][i] = tmp[r - 1 - i][j];

    swap(r, c);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    while (K--)
    {
        cin >> r >> c;
        for (int j = 0; j < r; j++)
            for (int i = 0; i < c; i++)
                cin >> sticker[j][i];

        for (int rot = 0; rot < 4; rot++)
        {
            for (int j = 0; j <= N - r; j++)
            {
                for (int i = 0; i <= M - c; i++)
                {
                    bool pasted = try_paste(j, i);
                    if (pasted)
                        goto next_sticker;
                }
            }
            rotate_sticker();
        }
    next_sticker:
        continue;
    }

    int ans = 0;
    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
            ans += notebook[j][i];

    cout << ans << '\n';
}