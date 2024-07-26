#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int getArea(vector<vector<int>> *board, int y, int x)
{
    int h = board->size();
    int w = (*board)[0].size();

    int area = 0;
    queue<pair<int, int>> q;
    (*board)[y][x] = 0;
    q.push(pair(y, x));

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        area += 1;

        for (int k = 0; k < 4; k++)
        {
            int ny = cy + dy[k];
            int nx = cx + dx[k];
            if (0 <= ny && ny < h && 0 <= nx && nx < w)
            {
                if ((*board)[ny][nx] == 1)
                {
                    (*board)[ny][nx] = 0;

                    q.push(pair(ny, nx));
                }
            }
        }
    }

    return area;
}

pair<int, int> solve(vector<vector<int>> *board)
{
    int cnt = 0;
    int max_area = 0;

    for (int j = 0; j < board->size(); j++)
    {
        for (int i = 0; i < (*board)[0].size(); i++)
        {
            if ((*board)[j][i] != 0)
            {
                cnt += 1;
                max_area = max(getArea(board, j, i), max_area);
            }
        }
    }

    return pair(cnt, max_area);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            cin >> board[j][i];
        }
    }

    pair<int, int> ans = solve(&board);
    cout << ans.first << endl
         << ans.second << endl;
}