#include <iostream>
#include <queue>
#include <vector>

#define INF 999999999

using namespace std;

int N, E, v1, v2;
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
    for (int i = 1; i <= N; i++)
        dist[i] = INF;
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

int getDistSum(int route, int to)
{
    if (route != INF && dist[to] != INF)
        return route + dist[to];
    else
        return INF;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> E;

    int from, to, cost;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> cost;
        edge[from].push_back(make_pair(cost, to));
        edge[to].push_back(make_pair(cost, from));
    }

    cin >> v1 >> v2;
    // route1 : 1 -> v1 -> v2 -> N
    // route2 : 1 -> v2 -> v1 -> N
    int route1 = 0, route2 = 0;
    dijkstra(1);
    route1 = getDistSum(route1, v1);
    route2 = getDistSum(route2, v2);

    dijkstra(v1);
    route1 = getDistSum(route1, v2);
    route2 = getDistSum(route2, N);

    dijkstra(v2);
    route1 = getDistSum(route1, N);
    route2 = getDistSum(route2, v1);

    if (route1 == INF && route2 == INF)
        cout << "-1\n";
    else
        cout << min(route1, route2);
}