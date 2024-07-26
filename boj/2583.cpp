#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, K;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void setupBoard(vector<vector<bool>> *board)
{
    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            (*board)[j][i] = true;
        }
    }

    for (int k = 0; k < K; k++)
    {
        int lux, luy, rdx, rdy;
        cin >> lux >> luy >> rdx >> rdy;
        for (int j = luy; j < rdy; j++)
        {
            for (int i = lux; i < rdx; i++)
            {
                (*board)[j][i] = false;
            }
        }
    }
}

int getArea(vector<vector<bool>> *board, int y, int x)
{
    int area_size = 0;
    queue<pair<int, int>> q;
    (*board)[y][x] = false;
    q.push(pair(y, x));
    area_size += 1;

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if (0 <= ny && ny < M && 0 <= nx && nx < N)
            {
                if ((*board)[ny][nx])
                {
                    (*board)[ny][nx] = false;
                    q.push(pair(ny, nx));
                    area_size += 1;
                }
            }
        }
    }
    return area_size;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;

    vector<vector<bool>> board(N, vector<bool>(M));
    setupBoard(&board);

    vector<int> ans;

    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (board[j][i])
            {
                ans.emplace_back(getArea(&board, j, i));
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
}