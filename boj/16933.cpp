#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, K;
int board[1000][1000];
int visited[1000][1000][2];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int j = 0; j < N; j++)
    {
        string s;
        cin >> s;
        for (int i = 0; i < M; i++)
            board[j][i] = s[i] - '0';
    }
    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
            fill(visited[j][i], visited[j][i] + 2, K + 1);

    queue<tuple<int, int, int>> q; // {y, x, t}
    visited[0][0][0] = 0;
    q.push({0, 0, 0});

    int ans = -2;
    while (!q.empty())
    {
        auto [cy, cx, ct] = q.front();
        int ck = visited[cy][cx][ct % 2];
        q.pop();

        if (cy == N - 1 && cx == M - 1)
        {
            ans = ct;
            break;
        }

        for (int d = 0; d < 4; d++)
        {
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            int nt = ct + 1;

            if (0 > ny || ny >= N || 0 > nx || nx >= M)
                continue;

            if (board[ny][nx] == 0)
            {
                if (visited[ny][nx][nt % 2] <= ck)
                    continue;

                visited[ny][nx][nt % 2] = ck;
                q.push({ny, nx, nt});
            }
            else if (board[ny][nx] == 1)
            {
                if (ck >= K)
                    continue;

                if (ct % 2 == 0)
                {
                    if (visited[ny][nx][nt % 2] <= ck + 1)
                        continue;
                    visited[ny][nx][nt % 2] = ck + 1;
                    q.push({ny, nx, nt});
                }
                else
                {
                    if (visited[cy][cx][nt % 2] <= ck)
                        continue;
                    visited[cy][cx][nt % 2] = ck;
                    q.push({cy, cx, nt});
                }
            }
        }
    }

    cout << ans + 1 << '\n';
}

/*
#14442에 시간 조건이 추가. 공간복잡도 O(2NM) 풀이로 해결했다.
덕분에 수정하다 64~83행이 아주 헷갈렸다. O(2NMK) 풀이는 맨 아래 참고.

밤에는 벽을 못 부수므로 밤에 지나가고 싶으면 기다려야 한다. (71~75행)
그냥 (ny, nx)로 움직이고 nt+1 하면 되는거 아닌가? 싶을 수 있지만
BFS가 시간 순서대로 돌아가므로 2턴 뒤의 시간을 당겨 넣어버리면 이상한
답이 나올 수 있다. 우선순위 큐를 쓰면 되기야 하겠지만 O(logN) 곱해져서
쓰면 손해일 듯.

공간복잡도 O(2NMK) 풀이: https://www.acmicpc.net/submit/16933/80181457
*/