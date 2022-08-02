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
queue<tuple<pair<int, int>, bool, int>> q;

bool inBoard(int y, int x)
{
    return (0 <= y && y <= N - 1 && 0 <= x && x <= M - 1);
}

int bfs()
{
    q.push(make_tuple(make_pair(0, 0), 0, 1));
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

            if (!inBoard(ny, nx) || visited[ny][nx][broken])
                continue;

            if (map[ny][nx] == '0')
            {
                visited[ny][nx][broken] = true;
                if (!broken)
                    visited[ny][nx][!broken] = true;
                count[ny][nx] = cnt + 1;
                q.push(make_tuple(make_pair(ny, nx), broken, cnt + 1));
            }
            if (map[ny][nx] == '1' && !broken)
            {
                visited[ny][nx][1] = true;
                count[ny][nx] = cnt + 1;
                q.push(make_tuple(make_pair(ny, nx), 1, cnt + 1));
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> map[i];

    cout << bfs();
}