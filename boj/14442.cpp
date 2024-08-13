#include <iostream>
#include <queue>

using namespace std;

int board[1000][1000];
bool visited[1001][1001][11];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

struct CellStat
{
    int y, x, k, t;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for (int j = 0; j < N; j++)
    {
        string s;
        cin >> s;
        for (int i = 0; i < M; i++)
            board[j][i] = s[i] - '0';
    }

    queue<CellStat> q;
    visited[0][0][0] = true;
    q.push(CellStat{0, 0, 0});

    int ans = -2;
    while (!q.empty())
    {
        int cy = q.front().y;
        int cx = q.front().x;
        int ck = q.front().k;
        int ct = q.front().t;
        q.pop();

        if (cy == N - 1 && cx == M - 1)
        {
            ans = ct;
            break;
        }

        for (int k = 0; k < 4; k++)
        {
            int ny = cy + dy[k];
            int nx = cx + dx[k];
            if (0 > ny || ny >= N || 0 > nx || nx >= M)
                continue;

            if (board[ny][nx] == 0 && !visited[ny][nx][ck])
            {
                visited[ny][nx][ck] = true;
                q.push(CellStat{ny, nx, ck, ct + 1});
            }
            else if (ck < K && !visited[ny][nx][ck + 1])
            {
                visited[ny][nx][ck + 1] = true;
                q.push(CellStat{ny, nx, ck + 1, ct + 1});
            }
        }
    }

    cout << ans + 1 << '\n';
}

/*
#1600과 동일한 아이디어.
똑같이 공간을 O(NM)만 쓰고 풀 수 있다.
시작점과 끝점을 경로 길이에 포함함에 유의.
*/