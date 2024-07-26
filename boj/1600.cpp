#include <iostream>
#include <queue>

using namespace std;

int K, W, H;
int hdy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int hdx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int mdy[4] = {0, -1, 1, 0};
int mdx[4] = {1, 0, 0, -1};

struct MoveStat
{
    int k;
    int y;
    int x;
    int time;
};

inline bool inBoard(int y, int x)
{
    return (0 <= y && y < H) && (0 <= x && x < W);
}

int main()
{
    cin >> K;
    cin >> W >> H;

    int board[200][200];
    for (int j = 0; j < H; j++)
        for (int i = 0; i < W; i++)
            cin >> board[j][i];

    queue<MoveStat> q;
    bool visited[200][200][30] = {false};
    visited[0][0][0] = true;
    q.push(MoveStat{K, 0, 0, 0});

    int ans = -1;
    while (!q.empty())
    {
        int ck = q.front().k;
        int cy = q.front().y;
        int cx = q.front().x;
        int ct = q.front().time;
        q.pop();

        if (cy == H - 1 && cx == W - 1)
        {
            ans = ct;
            break;
        }

        if (ck >= 1)
        {
            for (int i = 0; i < 8; i++)
            {
                int ny = cy + hdy[i];
                int nx = cx + hdx[i];
                int nt = ct + 1;

                if (inBoard(ny, nx) && board[ny][nx] != 1 && !visited[ny][nx][ck - 1])
                {
                    visited[ny][nx][ck - 1] = true;
                    q.push(MoveStat{ck - 1, ny, nx, nt});
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + mdy[i];
            int nx = cx + mdx[i];
            int nt = ct + 1;

            if (inBoard(ny, nx) && board[ny][nx] != 1 && !visited[ny][nx][ck])
            {
                visited[ny][nx][ck] = true;
                q.push(MoveStat{ck, ny, nx, nt});
            }
        }
    }

    cout << ans << '\n';
}