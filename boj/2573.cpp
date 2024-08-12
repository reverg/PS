#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int melt_ice(int board[300][300], int r, int c)
{
    bool visited[300][300] = {false};

    // melt ice
    int pieces = 0;
    vector<pair<pair<int, int>, int>> melted_ice;
    for (int j = 0; j < r; j++)
    {
        for (int i = 0; i < c; i++)
        {
            if (board[j][i] > 0 && !visited[j][i])
            {
                pieces++;

                // bfs
                queue<pair<int, int>> q;
                q.push({j, i});
                visited[j][i] = true;

                while (!q.empty())
                {
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();

                    int adj_water = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int ny = cy + dy[k];
                        int nx = cx + dx[k];

                        if (0 > ny || ny >= r || 0 > nx || nx >= c)
                            continue;

                        if (board[ny][nx] == 0)
                            adj_water++;
                        else if (!visited[ny][nx])
                        {
                            q.push({ny, nx});
                            visited[ny][nx] = true;
                        }
                    }

                    if (adj_water > 0)
                        melted_ice.push_back({{cy, cx}, max(board[cy][cx] - adj_water, 0)});
                }
            }
        }
    }

    // update board
    for (int i = 0; i < melted_ice.size(); i++)
        board[melted_ice[i].first.first][melted_ice[i].first.second] = melted_ice[i].second;

    return pieces;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int board[300][300] = {0};
    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
            cin >> board[j][i];

    int time = 0;
    while (true)
    {
        int pieces = melt_ice(board, N, M);

        if (pieces >= 2)
        {
            cout << time << '\n';
            break;
        }
        else if (pieces == 0)
        {
            cout << "0\n";
            break;
        }

        time++;
    }
}