#include <iostream>

using namespace std;

int N, L;
int board[100][100];

void rotate_board() // 시계방향 90도 회전
{
    int tmp[100][100];
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            tmp[j][i] = board[j][i];

    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            board[j][i] = tmp[N - 1 - i][j];
}

int count_roads()
{
    int cnt = 0;

    for (int j = 0; j < N; j++)
    {
        int cl = 1;
        bool is_road = true;
        for (int i = 0; i < N - 1; i++)
        {
            if (board[j][i] == board[j][i + 1])
                cl++;
            else if ((board[j][i] + 1 == board[j][i + 1]) && cl >= L)
                cl = 1;
            else if ((board[j][i] - 1 == board[j][i + 1]) && cl >= 0)
                cl = -L + 1;
            else
            {
                is_road = false;
                break;
            }
        }

        if (is_road && cl >= 0)
            cnt++;
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            cin >> board[j][i];

    int ans = 0;
    ans += count_roads();
    rotate_board();
    ans += count_roads();

    cout << ans << '\n';
}