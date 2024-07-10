#include <iostream>
#include <queue>

using namespace std;

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
    int N, K;
    cin >> N >> K;
    if (N == K)
        cout << 0 << '\n';
    else
    {
        int ans = bfs(N, K);
        cout << ans << '\n';
    }
}