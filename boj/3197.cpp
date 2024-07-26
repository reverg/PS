#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
char board[1501][1501];
bool visited[1501][1501];
vector<pair<int, int>> swans;
queue<pair<int, int>> swanQ, waterQ;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

inline bool inboard(int y, int x)
{
    return 0 <= y && y < R && 0 <= x && x < C;
}

void meltIce()
{
    int qs = waterQ.size();
    while (qs--)
    {
        int cy = waterQ.front().first;
        int cx = waterQ.front().second;
        waterQ.pop();

        for (int k = 0; k < 4; k++)
        {
            int ny = cy + dy[k];
            int nx = cx + dx[k];
            if (inboard(ny, nx) && board[ny][nx] == 'X')
            {
                board[ny][nx] = '.';
                waterQ.push({ny, nx});
            }
        }
    }
}

bool canMeet()
{
    queue<pair<int, int>> q;

    while (!swanQ.empty())
    {
        int cy = swanQ.front().first;
        int cx = swanQ.front().second;
        swanQ.pop();
        if (cy == swans[1].first && cx == swans[1].second)
            return true;

        for (int k = 0; k < 4; k++)
        {
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if (!inboard(ny, nx) || visited[ny][nx])
                continue;

            visited[ny][nx] = true;
            if (board[ny][nx] == 'X')
                q.push({ny, nx});
            else
                swanQ.push({ny, nx});
        }
    }

    swanQ = q;
    return false;
}

int main()
{
    cin >> R >> C;

    for (int j = 0; j < R; j++)
    {
        for (int i = 0; i < C; i++)
        {
            cin >> board[j][i];

            if (board[j][i] == 'L')
            {
                swans.push_back({j, i});
                waterQ.push({j, i});
            }
            else if (board[j][i] == '.')
            {
                waterQ.push({j, i});
            }
        }
    }

    swanQ.push({swans[0].first, swans[0].second});

    int time = 0;
    while (true)
    {
        if (canMeet())
            break;
        time++;
        meltIce();
    }
    cout << time << '\n';
}