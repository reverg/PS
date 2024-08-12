#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
string map[1000];
// 1 for broken, 0 for not
bool visited[1000][1000][2] = {false};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int count[1000][1000];
// {y, x}, broken, count
queue<tuple<pair<int, int>, int, int>> q;

int bfs()
{
    q.push({{0, 0}, 0, 1});
    visited[0][0][0] = true;
    visited[0][0][1] = true;
    while (!q.empty())
    {
        int y = get<0>(q.front()).first;
        int x = get<0>(q.front()).second;
        int broken = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();

        if (y == N - 1 && x == M - 1)
            return cnt;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 > ny || ny >= N || 0 > x || x >= M)
                continue;
            if (visited[ny][nx][broken])
                continue;

            if (map[ny][nx] == '0')
            {
                visited[ny][nx][broken] = true;
                if (!broken)
                    visited[ny][nx][!broken] = true;
                count[ny][nx] = cnt + 1;
                q.push({{ny, nx}, broken, cnt + 1});
            }
            if (map[ny][nx] == '1' && !broken)
            {
                visited[ny][nx][1] = true;
                count[ny][nx] = cnt + 1;
                q.push({{ny, nx}, 1, cnt + 1});
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> map[i];

    cout << bfs() << '\n';
}

/*
벽을 부쉈는지를 추가로 저장해서 bfs를 돌리면 되는 문제.
bfs이므로 시간순으로 도달하는데, 벽을 부수지 않고 도달하면 더 좋으므로
벽을 부수고 도달하는 시간까지 방문 처리해도 된다. (47 ~ 48행)
*/