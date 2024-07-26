#include <iostream>
#include <queue>

using namespace std;

char board[5][5];
int ans_cnt = 0;
bool included[25];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

inline bool inboard(int y, int x)
{
    return (0 <= y && y < 5) && (0 <= x && x < 5);
}

bool bfs(int pos)
{
    int cnt = 0;
    bool visited[5][5] = {false};
    queue<pair<int, int>> q;
    q.push({pos / 5, pos % 5});
    visited[pos / 5][pos % 5] = true;

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        cnt++;
        if (cnt == 7)
            return true;

        for (int k = 0; k < 4; k++)
        {
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if (inboard(ny, nx) && included[ny * 5 + nx] && !visited[ny][nx])
            {
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }

    return false;
}

void backtrack(int cnt, int pos, int s)
{
    if (cnt == 7)
    {
        if (s >= 4)
        {
            if (bfs(pos))
                ans_cnt++;
        }
        return;
    }

    for (int i = pos; i < 25; i++)
    {
        if (included[i])
            continue;

        included[i] = true;
        backtrack(cnt + 1, i, s + (board[i / 5][i % 5] == 'S'));
        included[i] = false;
    }
}

int main()
{
    for (int j = 0; j < 5; j++)
        cin >> board[j];

    backtrack(0, 0, 0);

    cout << ans_cnt << '\n';
}