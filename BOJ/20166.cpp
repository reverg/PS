#include <iostream>
#include <queue>
#include <unordered_map>
#include <tuple>

using namespace std;

int N, M, K;
char board[10][10];
unordered_map<string, int> m;
int dy[8] = {0, -1, 0, 1, -1, -1, 1, 1};
int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};

void bfs(int y, int x)
{
    queue<tuple<int, int, string>> q;
    string bs = "";
    bs += board[y][x];
    m[bs]++;
    q.push({y, x, bs});

    while (!q.empty())
    {
        int cy, cx;
        string cs;
        tie(cy, cx, cs) = q.front();
        q.pop();

        for (int k = 0; k < 8; k++)
        {
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if (ny < 0)
                ny += N;
            if (ny >= N)
                ny -= N;
            if (nx < 0)
                nx += M;
            if (nx >= M)
                nx -= M;

            string ns = cs + board[ny][nx];
            m[ns]++;

            if (ns.length() < 5)
                q.push({ny, nx, ns});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
            cin >> board[j][i];

    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
            bfs(j, i);

    string godLoves;
    for (int i = 0; i < K; i++)
    {
        cin >> godLoves;
        cout << m[godLoves] << '\n';
    }
}