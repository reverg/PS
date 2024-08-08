#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;

int N, E, v1, v2;
int dist[20001];
vector<pair<int, int>> edge[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void dijkstra(int start)
{
    fill(dist, dist + N + 1, INF);

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        for (int i = 0; i < edge[cur_node].size(); i++)
        {
            int next_dist = edge[cur_node][i].first;
            int next_node = edge[cur_node][i].second;
            if (dist[next_node] > cur_cost + next_dist)
            {
                dist[next_node] = cur_cost + next_dist;
                pq.push({dist[next_node], next_node});
            }
        }
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

/*
다익스트라를 3번 쓰는 문제. O(ElogE) 3번이라 충분하다.
dist 합 구할 때 overflow 안 나게 유의해야 한다...
*/