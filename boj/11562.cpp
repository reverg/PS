#include <iostream>

#define INF 1e9

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M;

    int dist[251][251];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dist[i][j] = (i == j ? 0 : INF);

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