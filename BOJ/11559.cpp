#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char board[12][6];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void fallBoard()
{
    for (int i = 0; i < 6; i++)
    {
        vector<char> v;
        for (int j = 11; j >= 0; j--)
            if (board[j][i] != '.')
                v.push_back(board[j][i]);

        int yidx = 11;
        for (char c : v)
        {
            board[yidx][i] = c;
            yidx--;
        }
        while (yidx >= 0)
        {
            board[yidx][i] = '.';
            yidx--;
        }
    }
}

bool pang(int y, int x)
{
    char color = board[y][x];
    bool visited[12][6] = {false};

    queue<pair<int, int>> q;
    vector<pair<int, int>> puyos;
    visited[y][x] = true;
    q.push({y, x});
    puyos.push_back({y, x});

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if (0 > ny || ny >= 12 || 0 > nx || nx >= 6)
                continue;
            if (visited[ny][nx] || board[ny][nx] != color)
                continue;

            visited[ny][nx] = true;
            q.push({ny, nx});
            puyos.push_back({ny, nx});
        }
    }

    if (puyos.size() >= 4)
    {
        for (auto [j, i] : puyos)
            board[j][i] = '.';
        return true;
    }
    else
        return false;
}

bool check()
{
    bool changed = false;

    for (int j = 0; j < 12; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            if (board[j][i] != '.')
            {
                if (pang(j, i))
                    changed = true;
            }
        }
    }

    if (changed)
    {
        fallBoard();
        return true;
    }
    else
        return false;
}

int main()
{
    for (int j = 0; j < 12; j++)
        for (int i = 0; i < 6; i++)
            cin >> board[j][i];

    int ans = 0;
    while (true)
    {
        if (check() == false)
            break;
        ans++;
    }

    cout << ans << '\n';
}