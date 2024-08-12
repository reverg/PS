#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> board(h, vector<char>(w));
queue<CellStat> q;
CellStat sanggeun;

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

    for (int j = 0; j < h; j++)
    {
        for (int i = 0; i < w; i++)
        {
            cin >> board[j][i];
            if (board[j][i] == '@')
                sanggeun = CellStat{'@', j, i, 0};
            if (board[j][i] == '*')
                q.push(CellStat{'*', j, i, 0});
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

                if (0 > ny || ny >= h || 0 > nx || nx >= w)
                    continue;

                if (board[ny][nx] == '.' || board[ny][nx] == '@')
                {
                    board[ny][nx] = '*';
                    q.push(CellStat{'*', ny, nx, curCell.time + 1});
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
        solve();
}

/*
불에 대해 먼저 DFS를 돌리고 상근이에 대해 BFS를 돌려 푸는 방법도 있지만,
불을 먼저 큐에 넣고 상근이를 큐에 넣은 뒤 BFS를 돌리면 큐 하나로도 가능하다.
상근이는 불이 붙으려는 곳에 갈 수 없으므로 불이 먼저 움직여야 정답이 나온다.
불이 붙음과 동시에 다른 칸으로 움직이는게 가능하므로 옮겨붙으려는 칸에
상근이가 있더라도 불로 덮어씌운다. 상근이는 큐에 미리 들어가 있기 때문에
상근이가 어디에 있는지 정보가 손실되지 않는다.
*/