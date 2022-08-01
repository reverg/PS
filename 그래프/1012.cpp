#include <iostream>
#include <cstring>

using namespace std;

int T, M, N;
int arr[50][50] = {
    0,
};
bool visited[50][50] = {
    false,
};

int cnt;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (0 <= nx && nx < M && 0 <= ny && ny < N)
        {
            if (arr[nx][ny] == 1 && !visited[nx][ny])
                dfs(nx, ny);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    int K, X, Y;
    while (T--)
    {
        cnt = 0;
        cin >> M >> N >> K;
        while (K--)
        {
            cin >> X >> Y;
            arr[X][Y] = 1;
        }
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[i][j] == 1 && !visited[i][j])
                {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
    }
}