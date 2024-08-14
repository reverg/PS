#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int, int>> switches[101][101];
bool lighted[101][101];
bool visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        switches[x][y].push_back({a, b});
    }

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

/*
새로 불이 켜진 곳이 이전에 방문했던 곳과 인접해있으면 그 방에
도달할 수 있다는 뜻이므로 큐에 추가해준다. 끊겨있다가 불이
켜지면서 새로 도달 가능해진 방도 있으므로 인접한 방들도 불이
켜져있는데 방문하지 않았으면 큐에 추가해줘야 한다.
*/