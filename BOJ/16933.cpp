#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int board[1000][1000];
bool visited[1000][1000][11][2];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

struct CellStat
{
    int y, x, k, t;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int j = 0; j < N; j++)
    {
        string s;
        cin >> s;
        for (int i = 0; i < M; i++)
        {
            board[j][i] = s[i] - '0';
        }
    }

    int ans = -2;
    queue<CellStat> q;
    visited[0][0][0][0] = true;
    q.push(CellStat{0, 0, 0, 0});

    while (!q.empty())
    {
        int cy = q.front().y;
        int cx = q.front().x;
        int ck = q.front().k;
        int ct = q.front().t;
        q.pop();

        if (cy == N - 1 && cx == M - 1)
        {
            ans = ct;
            break;
        }

        for (int d = 0; d < 4; d++)
        {
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            int nt = ct + 1;

            if (0 <= ny && ny < N && 0 <= nx && nx < M)
            {
                if (board[ny][nx] == 0 && !visited[ny][nx][ck][nt % 2])
                {
                    visited[ny][nx][ck][nt % 2] = true;
                    q.push(CellStat{ny, nx, ck, nt});
                }

                else if (board[ny][nx] == 1 && ck < K)
                {
                    if (ct % 2 == 0 && !visited[ny][nx][ck + 1][nt % 2])
                    {
                        visited[ny][nx][ck + 1][nt % 2] = true;
                        q.push(CellStat{ny, nx, ck + 1, nt});
                    }
                    else if (!visited[cy][cx][ck][nt % 2])
                    {
                        visited[cy][cx][ck][nt % 2] = true;
                        q.push(CellStat{cy, cx, ck, nt});
                    }
                }
            }
        }
    }

    cout << ans + 1 << '\n';
}