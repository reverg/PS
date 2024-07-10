#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, P;
int S[10];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

struct Loc
{
    int y, x;
};

void solve(char board[][1000])
{
    queue<Loc> q[P + 1];
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            cin >> board[j][i];
            if (board[j][i] != '.' && board[j][i] != '#')
                q[board[j][i] - '0'].push(Loc{j, i});
        }
    }

    while (true)
    {
        bool constructed = false;
        for (int p = 1; p <= P; p++)
        {
            int s_len = S[p];
            while (!q[p].empty() && s_len--)
            {
                int states = q[p].size();
                for (int st = 0; st < states; st++)
                {
                    int cy = q[p].front().y;
                    int cx = q[p].front().x;
                    q[p].pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int ny = cy + dy[k];
                        int nx = cx + dx[k];

                        if (0 > ny || ny >= N || 0 > nx || nx >= M)
                            continue;

                        if (board[ny][nx] == '.')
                        {
                            board[ny][nx] = char(p + '0');
                            q[p].push(Loc{ny, nx});
                            constructed = true;
                        }
                    }
                }
            }
        }
        if (!constructed)
            break;
    }
}

int main()
{
    cin >> N >> M >> P;
    for (int i = 1; i <= P; i++)
        cin >> S[i];

    char board[1000][1000];

    solve(board);

    int ans[10];
    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
            ans[board[j][i] - '0']++;

    for (int i = 1; i <= P; i++)
        cout << ans[i] << ' ';
    return 0;
}