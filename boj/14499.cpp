#include <iostream>

using namespace std;

int N, M, x, y, K;
int dice[6] = {0, 0, 0, 0, 0, 0};
int board[20][20];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

void roll(int dir)
{
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        return;

    x = nx;
    y = ny;

    // 예시 전개도 135642 기준
    // 위 동 남 아래 서 북
    int tmp[6];
    copy(dice, dice + 6, tmp);
    int temp = dice[0];

    if (dir == 1)
    {
        // 415362
        dice[0] = tmp[4];
        dice[1] = tmp[0];
        dice[2] = tmp[2];
        dice[3] = tmp[1];
        dice[4] = tmp[3];
        dice[5] = tmp[5];
    }
    else if (dir == 2)
    {
        // 365412
        dice[0] = tmp[1];
        dice[1] = tmp[3];
        dice[2] = tmp[2];
        dice[3] = tmp[4];
        dice[4] = tmp[0];
        dice[5] = tmp[5];
    }
    else if (dir == 3)
    {
        // 536241
        dice[0] = tmp[2];
        dice[1] = tmp[1];
        dice[2] = tmp[3];
        dice[3] = tmp[5];
        dice[4] = tmp[4];
        dice[5] = tmp[0];
    }
    else if (dir == 4)
    {
        // 231546
        dice[0] = tmp[5];
        dice[1] = tmp[1];
        dice[2] = tmp[0];
        dice[3] = tmp[2];
        dice[4] = tmp[4];
        dice[5] = tmp[3];
    }

    if (board[nx][ny] == 0)
        board[nx][ny] = dice[3];
    else
    {
        dice[3] = board[nx][ny];
        board[nx][ny] = 0;
    }

    cout << dice[0] << '\n';
}

int main()
{
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    while (K--)
    {
        int dir;
        cin >> dir;
        roll(dir);
    }
}