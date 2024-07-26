#include <iostream>
#include <vector>

#define INF 999999999

using namespace std;

int V, E;
bool cycle = false;

long long dist[401][401];
vector<pair<pair<int, int>, int>> edge;

void Initialize()
{
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            dist[i][j] = INF;
}

void GetInput()
{
    int from, to, cost;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> cost;
        if (dist[from][to] > cost)
            dist[from][to] = cost;
    }
}

void PrintResult()
{
    int cycle_min = INF;
    for (int idx = 1; idx <= V; idx++)
    {
        if (dist[idx][idx] < cycle_min)
            cycle_min = dist[idx][idx];
    }
    cout << (cycle_min == INF ? -1 : cycle_min) << '\n';
}

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

    Initialize();

    GetInput();

    FloydWarshall();

    PrintResult();
}