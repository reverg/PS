#include <iostream>
#include <vector>

#define INF 999999999

using namespace std;

int N, M;
bool cycle = false;

long long dist[501];
vector<pair<int, int>> edge[501];

void BellmanFord(int start)
{
    for (int i = 1; i <= N; i++)
        dist[i] = INF;
    dist[start] = 0;

    // get distance
    for (int k = 1; k <= N - 1; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < edge[i].size(); j++)
            {
                int next = edge[i][j].first;
                int cost = edge[i][j].second;

                if (dist[i] != INF && dist[i] + cost < dist[next])
                    dist[next] = dist[i] + cost;
            }
        }
    }

    // check negative cycle
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < edge[i].size(); j++)
        {
            int next = edge[i][j].first;
            int cost = edge[i][j].second;
            if (dist[i] != INF && dist[i] + cost < dist[next])
            {
                cycle = true;
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int from, to, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        edge[from].push_back(make_pair(to, cost));
    }

    BellmanFord(1);

    if (!cycle)
    {
        for (int i = 2; i <= N; i++)
            cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
    }
    else
        cout << "-1\n";
}