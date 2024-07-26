#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int N, M, S, E;
vector<pair<int, int>> graph[200001];

int pre[200001] = {0};
bool used[200001] = {false};

int dijkstra(int start, int end)
{
    priority_queue<pair<int, int>> pq;
    int dist[200001];

    fill(dist, dist + 200001, INF);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [cur_dist, cur_node] = pq.top();
        cur_dist *= -1;
        pq.pop();

        if (dist[cur_node] != cur_dist)
            continue;

        for (auto [next_node, cost] : graph[cur_node])
        {
            if (used[next_node])
                continue;

            int ndist = dist[cur_node] + cost;
            if (dist[next_node] > ndist)
            {
                pre[next_node] = cur_node;
                dist[next_node] = ndist;
                pq.push({-ndist, next_node});
            }
            else if (dist[next_node] == ndist)
            {
                pre[next_node] = min(pre[next_node], cur_node);
            }
        }
    }

    return dist[end];
}

void remove_path()
{
    int cur = S;
    while (cur > 0)
    {
        used[cur] = true;
        cur = pre[cur];
    }

    used[E] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> S >> E;

    // Dijkstra 1
    // find path from end to start: this helps choosing lexical ascending order
    int ans = dijkstra(E, S);

    // remove shortest paths
    remove_path();

    // Dijkstra 2
    ans += dijkstra(S, E);

    cout << ans << '\n';
}