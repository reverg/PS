
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int bitLimit;
int dist[1 << 20];
queue<int> q;

int main()
{
    cin >> N >> M;

    bitLimit = 1;
    while (bitLimit <= N)
        bitLimit <<= 1;

    fill(dist, dist + bitLimit, -1);

    for (int i = 0; i < M; i++)
    {
        int p;
        cin >> p;
        dist[p] = 0;
        q.push(p);
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int b = 1; b < bitLimit; b <<= 1)
        {
            int nx = x ^ b;

            if (dist[nx] != -1)
                continue;

            dist[nx] = dist[x] + 1;
            q.push(nx);
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; i++)
        ans = max(ans, dist[i]);
    cout << ans << '\n';
}

/*
비트마스킹을 이용한 BFS. 아이디어만 알면 straightforward하다.
N의 범위가 10진수 기반이라 이진수로 깔끔하게 1...1꼴이 안 되는데,
편의를 위해 dist 배열을 좀 넉넉하게 잡고 처리했다.
*/