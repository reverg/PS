#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> switches[101][101];
    for (int i = 0; i < M; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        switches[x][y].push_back({a, b});
    }

    bool lighted[101][101] = {false};
    bool visited[101][101] = {false};

    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;
    lighted[1][1] = true;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < switches[cx][cy].size(); i++)
        {
            int sx = switches[cx][cy][i].first;
            int sy = switches[cx][cy][i].second;
            lighted[sx][sy] = true;
            for (int k = 0; k < 4; k++)
            {
                // if we visited adjacent room of newly lighted room,
                // we can also visit newly lighted room
                int ax = sx + dx[k];
                int ay = sy + dy[k];

                if (ax < 0 || N < ax || ay < 0 || N < ay)
                    continue;

                if (visited[ax][ay] && !visited[sx][sy])
                {
                    visited[sx][sy] = true;
                    q.push({sx, sy});
                }
            }
        }

        for (int k = 0; k < 4; k++)
        {
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            if (nx < 0 || N < nx || ny < 0 || N < ny)
                continue;

            if (!visited[nx][ny] && lighted[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            ans += lighted[i][j];

    cout << ans << '\n';
}