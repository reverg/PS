#include <iostream>
#include <queue>

using namespace std;

int N, M;
string arr[100];
int visited[100][100];
int dist[100][100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void bfs(int x, int y)
{
    visited[x][y] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (0 <= nx && nx < N && 0 <= ny && ny < M)
            {
                if (arr[nx][ny] == '1' && !visited[nx][ny])
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    visited[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    bfs(0, 0);
    cout << dist[N - 1][M - 1] + 1;
}