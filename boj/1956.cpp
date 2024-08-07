#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;

int V, E;
bool cycle = false;
int dist[401][401];
vector<pair<pair<int, int>, int>> edge;

void FloydWarshall()
{
    for (int mid = 1; mid <= V; mid++)
        for (int from = 1; from <= V; from++)
            for (int to = 1; to <= V; to++)
                if (dist[from][mid] != INF && dist[mid][to] != INF)
                    dist[from][to] = min(dist[from][to], dist[from][mid] + dist[mid][to]);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> V >> E;

    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            dist[i][j] = INF;

    int from, to, cost;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> cost;
        if (dist[from][to] > cost)
            dist[from][to] = cost;
    }

    // floyd-warshall
    for (int mid = 1; mid <= V; mid++)
        for (int from = 1; from <= V; from++)
            for (int to = 1; to <= V; to++)
                if (dist[from][mid] != INF && dist[mid][to] != INF)
                    dist[from][to] = min(dist[from][to], dist[from][mid] + dist[mid][to]);

    int cycle_min = INF;
    for (int idx = 1; idx <= V; idx++)
    {
        if (dist[idx][idx] < cycle_min)
            cycle_min = dist[idx][idx];
    }
    cout << (cycle_min == INF ? -1 : cycle_min) << '\n';
}

/*
dist[i][j]+dist[j][i]의 최소값을 구해도 되지만, dist[i][i]=INF로
놓고 시작하면 자기 자신으로 돌아오는 경로의 최단거리가 구해진다.
좋은 발상을 배울 수 있는 문제.
*/