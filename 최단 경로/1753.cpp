#include <iostream>
#include <queue>
#include <vector>

#define INF 2000000

using namespace std;

int V, E, start;
int dist[20001];
vector<pair<int, int>> edge[20001];
priority_queue<pair<int, int>> pq;

void updateDist(int cur_node, int cur_cost)
{
    for (int i = 0; i < edge[cur_node].size(); i++)
    {
        int next_dist = edge[cur_node][i].first;
        int next_node = edge[cur_node][i].second;
        if (dist[next_node] > cur_cost + next_dist)
        {
            dist[next_node] = cur_cost + next_dist;
            pq.push(make_pair(-dist[next_node], next_node));
        }
    }
}

void dijkstra(int start)
{
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty())
    {
        int cur_cost = -pq.top().first;
        int cur_node = pq.top().second;

        pq.pop();

        updateDist(cur_node, cur_cost);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> V >> E;
    cin >> start;

    int from, to, cost;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> cost;
        edge[from].push_back(make_pair(cost, to));
    }
    for (int i = 1; i <= V; i++)
        dist[i] = INF;

    dijkstra(start);

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }
}