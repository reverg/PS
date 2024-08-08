#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, A, B;
vector<pair<int, int>> edges[1001];
long long dist[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra()
{
    pq.push({0, A});

    while (!pq.empty())
    {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (cur_cost != dist[cur_node])
            continue;

        for (int i = 0; i < edges[cur_node].size(); i++)
        {
            int next_node = edges[cur_node][i].first;
            int next_cost = edges[cur_node][i].second;
            if (dist[next_node] > dist[cur_node] + next_cost)
            {
                dist[next_node] = dist[cur_node] + next_cost;
                pq.push({dist[next_node], next_node});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edges[src].push_back(make_pair(dst, cost));
    }
    cin >> A >> B;

    fill(dist, dist + N + 1, INF);
    dist[A] = 0;

    dijkstra();

    cout << dist[B] << '\n';
}