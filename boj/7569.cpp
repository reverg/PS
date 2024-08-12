#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int M, N, H;
int arr[100][100][100];
int dist[100][100][100];
queue<tuple<int, int, int>> q;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void bfs()
{
    while (!q.empty())
    {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();

        for (int k = 0; k < 6; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nz = z + dz[k];

            if (0 > nx || nx >= M || 0 > ny || ny >= N || 0 > nz || nz >= H)
                continue;
            if (arr[nx][ny][nz] != 0)
                continue;

            dist[nx][ny][nz] = dist[x][y][z] + 1;
            arr[nx][ny][nz] = 1;
            q.push({nx, ny, nz});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    for (int k = 0; k < H; k++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int i = 0; i < M; i++)
            {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1)
                    q.push({i, j, k});
            }
        }
    }

    bfs();

    int day = -1;
    for (int k = 0; k < H; k++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int i = 0; i < M; i++)
            {
                if (arr[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
                day = max(day, dist[i][j][k]);
            }
        }
    }

    cout << day << '\n';
}