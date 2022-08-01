#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

int T, L;
bool visited[300][300];

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool inBoard(int x, int y)
{
    return (0 <= x && x < L && 0 <= y && y < L);
}

int bfs(int x1, int y1, int x2, int y2)
{
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(x1, y1, 0));
    memset(visited, false, sizeof(visited));
    visited[x1][y1] = true;

    while (!q.empty())
    {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int depth = get<2>(q.front());
        q.pop();

        if (x == x2 && y == y2)
            return depth;

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (inBoard(nx, ny) && visited[nx][ny] == false)
            {
                visited[nx][ny] = true;
                q.push(make_tuple(nx, ny, depth + 1));
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--)
    {
        cin >> L;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << bfs(x1, y1, x2, y2) << '\n';
    }
}