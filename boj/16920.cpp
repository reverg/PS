#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, P;
int S[10];
char board[1000][1000];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void solve()
{
    queue<pair<int, int>> q[P + 1];
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            cin >> board[j][i];
            if (board[j][i] != '.' && board[j][i] != '#')
                q[board[j][i] - '0'].push({j, i});
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
                    auto [cy, cx] = q[p].front();
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
                            q[p].push({ny, nx});
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

    solve();

    int ans[10];
    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
            ans[board[j][i] - '0']++;

    for (int i = 1; i <= P; i++)
        cout << ans[i] << ' ';
    return 0;
}

/*
턴을 나눠 BFS하는 문제. 처음 큐에 있는 원소 수만큼
확장을 해주면 1턴이 된다. 자주 사용되는 아이디어이므로
기억해두자. 지금 board를 전역변수로 뺐는데 BOJ에서는
main 안에 넣어주지 않으면 오답처리된다. 맞왜틀?
*/