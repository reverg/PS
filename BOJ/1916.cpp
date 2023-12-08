#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, A, B;
vector<pair<int, int>> edges[1001];
long long dist[1001];

void input()
{
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edges[src].push_back(make_pair(dst, cost));
    }
    cin >> A >> B;

    for (int i = 1; i <= N; i++)
    {
        dist[i] = 100000 * 1000;
    }
    dist[A] = 0;
}

void dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, A);

    while (!pq.empty())
    {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (cur_cost > dist[cur_node])
        {
            continue;
        }

        for (int i = 0; i < edges[cur_node].size(); i++)
        {
            int next_node = edges[cur_node][i].first;
            int next_cost = edges[cur_node][i].second;
            if (dist[next_node] > dist[cur_node] + next_cost)
            {
                dist[next_node] = dist[cur_node] + next_cost;
                pq.emplace(dist[next_node], next_node);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    dijkstra();
    cout << dist[B] << endl;
}