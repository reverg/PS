
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int bitLimit = 2;

int main()
{
    int N, M;
    cin >> N >> M;

    int bitLimit = 2;
    while (bitLimit <= N)
        bitLimit <<= 1;

    int dist[bitLimit];
    for (int i = 0; i < bitLimit; i++)
        dist[i] = -1;

    queue<int> q;
    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;
        dist[tmp] = 0;
        q.push(tmp);
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int b = 1; b < bitLimit; b <<= 1)
        {
            int nx = x ^ b;
            if (dist[nx] >= 0)
                continue;
            dist[nx] = dist[x] + 1;
            q.push(nx);
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; i++)
    {
        ans = max(ans, dist[i]);
    }
    cout << ans << '\n';
}