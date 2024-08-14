#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> q;
bool visited[500001][2];

int bfs(int n, int k)
{
    q.push(n);

    int time = 1;
    while (!q.empty())
    {
        k += time;
        if (k > 500000)
            return -1;

        if (visited[k][time % 2])
            return time;

        int qs = q.size();
        for (int i = 0; i < qs; i++)
        {
            int x = q.front();
            q.pop();

            for (int nx : {x - 1, x + 1, 2 * x})
            {
                if (nx == k)
                    return time;

                if (nx < 0 || nx > 500000 || visited[nx][time % 2])
                    continue;

                visited[nx][time % 2] = true;
                q.push(nx);
            }
        }
        time++;
    }
    return -1;
}

int main()
{
    cin >> N >> K;

    if (N == K)
        cout << 0 << '\n';
    else
    {
        int ans = bfs(N, K);
        cout << ans << '\n';
    }
}

/*
동생이 계속 이동하는데 수빈이는 같은 위치에 계속 있을 수 없다.
대신 앞뒤/뒤앞으로 이동해서 2초 후에 원래 자리로 돌아올 수 있으니
시간을 홀짝으로 나눠서 방문 여부를 체크하면 된다. 동생이 있는 위치
변경은 #16920처럼 턴을 나눠 BFS 하는 방식으로 해결.
*/