#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, K;
int dist[251][251];

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        fill(dist[i], dist[i] + N + 1, INF);
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int u, v, b;
        cin >> u >> v >> b;
        dist[u][v] = 0;
        dist[v][u] = (b == 1 ? 0 : 1);
    }

    for (int mid = 1; mid <= N; mid++)
        for (int from = 1; from <= N; from++)
            for (int to = 1; to <= N; to++)
                dist[from][to] = min(dist[from][to], dist[from][mid] + dist[mid][to]);

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << dist[u][v] << '\n';
    }
}

/*
갈 수 있는 간선은 비용 0, 단방향이라 있어도 못 가는 간선은
비용 1 취급한다. 플로이드를 쓰면 양방향으로 바꿔야 되는
간선 수는 dist 값과 동일해진다. 조건상 모든 길을 양방향으로
바꿔도 서로 도달 불가능한 건물들은 없으므로 INF 값이 남아있지 않다.
*/