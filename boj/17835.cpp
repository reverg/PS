#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<ll, int>> graph[100001];
    for (int i = 0; i < M; i++)
    {
        int from, to;
        ll cost;
        cin >> from >> to >> cost;
        graph[to].push_back({cost, from});
    }

    ll dist[100001];
    fill(dist, dist + N + 1, 1e18);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int i = 0; i < K; i++)
    {
        int city;
        cin >> city;
        dist[city] = 0;
        pq.push({0, city});
    }

    // Dijkstra
    while (!pq.empty())
    {
        pair<ll, ll> cur = pq.top();
        pq.pop();

        if (dist[cur.second] < cur.first)
            continue;

        for (auto next : graph[cur.second])
        {
            if (dist[next.second] > dist[cur.second] + next.first)
            {
                dist[next.second] = dist[cur.second] + next.first;
                pq.push({dist[next.second], next.second});
            }
        }
    }

    int max_idx = -1;
    ll max_dist = -1;
    for (int i = 1; i <= N; i++)
    {
        if (max_dist < dist[i])
        {
            max_idx = i;
            max_dist = dist[i];
        }
    }
    cout << max_idx << '\n'
         << max_dist << '\n';
}