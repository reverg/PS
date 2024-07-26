#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

struct CellStat
{
    char cellType;
    int y;
    int x;
    int time;
};

void solve()
{
    int w, h;
    cin >> w >> h;

    vector<vector<char>> board(h, vector<char>(w));
    queue<CellStat> q;
    CellStat sanggeun;
    for (int j = 0; j < h; j++)
    {
        for (int i = 0; i < w; i++)
        {
            cin >> board[j][i];
            if (board[j][i] == '@')
            {
                sanggeun = CellStat{'@', j, i, 0};
            }
            if (board[j][i] == '*')
            {
                q.push(CellStat{'*', j, i, 0});
            }
        }
    }
    q.push(sanggeun);

    while (!q.empty())
    {
        CellStat curCell = q.front();
        q.pop();

        if (curCell.cellType == '*')
        {
            for (int k = 0; k < 4; k++)
            {
                int ny = curCell.y + dy[k];
                int nx = curCell.x + dx[k];

                if (0 <= ny && ny < h && 0 <= nx && nx < w)
                {
                    if (board[ny][nx] == '.' || board[ny][nx] == '@')
                    {
                        board[ny][nx] = '*';
                        q.push(CellStat{'*', ny, nx, curCell.time + 1});
                    }
                }
            }
        }
        if (curCell.cellType == '@')
        {
            for (int k = 0; k < 4; k++)
            {
                int ny = curCell.y + dy[k];
                int nx = curCell.x + dx[k];

                if (ny < 0 || h <= ny || nx < 0 || w <= nx)
                {
                    cout << curCell.time + 1 << '\n';
                    return;
                }
                else
                {
                    if (board[ny][nx] == '.')
                    {
                        board[ny][nx] = '@';
                        q.push(CellStat{'@', ny, nx, curCell.time + 1});
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
}