#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[1000][1000];
int dist[1000][1000] = {0};
queue<pair<int, int>> q;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void bfs()
{
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (0 > nx || nx >= M || 0 > ny || ny >= N)
                continue;
            if (arr[ny][nx] != 0)
                continue;

            dist[ny][nx] = dist[y][x] + 1;
            arr[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            cin >> arr[j][i];
            if (arr[j][i] == 1)
                q.push({j, i});
        }
    }

    bfs();

    int day = -1;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            if (arr[j][i] == 0)
            {
                cout << -1;
                return 0;
            }
            day = max(day, dist[j][i]);
        }
    }

    cout << day << '\n';
}