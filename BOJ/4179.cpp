#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

struct CellStat
{
    char cellType;
    int y;
    int x;
    int time;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    vector<vector<char>> maze(R + 2, vector<char>(C + 2));
    queue<CellStat> q;
    pair<int, int> jihoon;
    for (int j = 0; j < R; j++)
    {
        for (int i = 0; i < C; i++)
        {
            cin >> maze[j][i];
            if (maze[j][i] == 'J')
            {
                jihoon = pair(j, i);
            }
            else if (maze[j][i] == 'F')
            {
                q.push(CellStat{'F', j, i, 0});
            }
        }
    }
    q.push(CellStat{'J', jihoon.first, jihoon.second, 0});

    int ans = -1;
    while (!q.empty())
    {
        CellStat cst = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int ny = cst.y + dy[k];
            int nx = cst.x + dx[k];

            if (cst.cellType == 'J')
            {
                if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                {
                    ans = cst.time + 1;
                    goto conclusion;
                }
                else
                {
                    if (maze[ny][nx] == '.')
                    {
                        maze[ny][nx] = 'J';
                        q.push(CellStat{'J', ny, nx, cst.time + 1});
                    }
                }
            }

            if (cst.cellType == 'F')
            {
                if (0 <= ny && ny < R && 0 <= nx && nx < R)
                {
                    if (maze[ny][nx] == '.' || maze[ny][nx] == 'J')
                    {
                        maze[ny][nx] = 'F';
                        q.push(CellStat{'F', ny, nx, cst.time + 1});
                    }
                }
            }
        }
    }

conclusion:
    if (ans != -1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}