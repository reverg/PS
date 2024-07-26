#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, m;
    int board[1001][1001];
    bool visited[1001][1001];
    queue<pair<pair<int, int>, int>> q;

    cin >> n >> m;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            cin >> board[j][i];
            if (board[j][i] == 2)
            {
                q.push(make_pair(make_pair(j, i), 0));
                board[j][i] = 0;
                visited[j][i] = true;
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> cur_pos = q.front().first;
        int cur_y = cur_pos.first, cur_x = cur_pos.second;
        int dist = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nxt_y = cur_y + dy[i], nxt_x = cur_x + dx[i];
            if (visited[nxt_y][nxt_x])
                continue;
            if (0 >= nxt_y || nxt_y > n || 0 >= nxt_x || nxt_x > m)
                continue;

            if (board[nxt_y][nxt_x] == 1)
            {
                visited[nxt_y][nxt_x] = true;
                board[nxt_y][nxt_x] = dist + 1;
                q.push(make_pair(make_pair(nxt_y, nxt_x), dist + 1));
            }
        }
    }

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            if (!visited[j][i] && board[j][i] == 1)
            {
                board[j][i] = -1;
            }
            cout << board[j][i] << ' ';
        }
        cout << '\n';
    }
}