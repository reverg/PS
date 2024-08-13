#include <iostream>
#include <queue>

using namespace std;

int K, W, H;
int board[200][200];
int visited[200][200];
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

int main()
{
    cin >> K;
    cin >> W >> H;

    for (int j = 0; j < H; j++)
        for (int i = 0; i < W; i++)
            cin >> board[j][i];
    for (int j = 0; j < H; j++)
        fill(visited[j], visited[j] + W, -1);

    queue<MoveStat> q;
    visited[0][0] = K;
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

                if (0 > ny || ny >= H || 0 > nx || nx >= W)
                    continue;
                if (board[ny][nx] == 1 || visited[ny][nx] >= ck - 1)
                    continue;

                visited[ny][nx] = ck - 1;
                q.push(MoveStat{ck - 1, ny, nx, nt});
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + mdy[i];
            int nx = cx + mdx[i];
            int nt = ct + 1;

            if (0 > ny || ny >= H || 0 > nx || nx >= W)
                continue;
            if (board[ny][nx] == 1 || visited[ny][nx] >= ck)
                continue;

            visited[ny][nx] = ck;
            q.push(MoveStat{ck, ny, nx, nt});
        }
    }

    cout << ans << '\n';
}

/*
3차원 BFS를 사용하는 문제.
굳이 k를 다른 차원으로 두지 않고 2차원 visited 배열의 값으로 넣으면 메모리를
더 아낄 수 있다. k번의 기회를 남기고 도달했으면 k-1번 이하의 기회가 남은 경우들에
비해 상위호환이므로 방문 여부를 따로 체크해주지 않아도 되기 때문이다.
이 풀이는 시간복잡도 O(MNK), 공간복잡도 O(MN).
*/