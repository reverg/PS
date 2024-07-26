#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define INF 1e9

using namespace std;

int N, M, K, S, D;
vector<pair<int, int>> graph[1001];
int tax[30001];
int dist[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    cin >> S >> D;

    for (int i = 0; i < M; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    for (int i = 1; i <= K; i++)
        cin >> tax[i];

    // Dijkstra
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
            dist[i][j] = INF;
    dist[S][0] = 0;

    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, S, 0});
    while (!pq.empty())
    {
        int cur_dist = -get<0>(pq.top());
        int cur_node = get<1>(pq.top());
        int cur_roads = get<2>(pq.top());
        pq.pop();

        if (dist[cur_node][cur_roads] < cur_dist)
            continue;

        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int next_node = graph[cur_node][i].first;
            int cost = graph[cur_node][i].second;

            int new_dist = cur_dist + cost;
            if (dist[next_node][cur_roads + 1] > new_dist)
            {
                dist[next_node][cur_roads + 1] = new_dist;
                pq.push({-new_dist, next_node, cur_roads + 1});
            }
        }
    }

    for (int k = 0; k <= K; k++)
    {
        int min_dist = INF;
        for (int i = 1; i <= N; i++)
        {
            dist[D][i] += i * tax[k];
            min_dist = min(min_dist, dist[D][i]);
        }
        cout << min_dist << '\n';
    }
}