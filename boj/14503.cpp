#include <iostream>

using namespace std;

int N, M;
int r, c, d;
int room[50][50];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool operate()
{
    //  1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
    if (room[r][c] == 0)
        room[r][c] = 2;

    // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
    if (room[r][c + 1] != 0 && room[r][c - 1] != 0 && room[r + 1][c] != 0 && room[r - 1][c] != 0)
    {
        int nr = r - dr[d];
        int nc = c - dc[d];

        // 2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
        if (room[nr][nc] != 1)
        {
            r = nr;
            c = nc;
            return false;
        }

        // 2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
        else
            return true;
    }
    // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
    else
    {
        // 3-1. 반시계 방향으로 90도 회전한다.
        d = (d + 3) % 4;

        // 3-2. 바라보는 방향으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (room[nr][nc] == 0)
        {
            r = nr;
            c = nc;
        }

        // 3-3. 1번으로 돌아간다.
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    cin >> r >> c >> d;

    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
            cin >> room[j][i];

    while (true)
    {
        bool finished = operate();
        if (finished)
            break;
    }

    int cleaned = 0;
    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
            if (room[j][i] == 2)
                cleaned++;

    cout << cleaned << '\n';
}