#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> graph[N + 1];
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, i});
        graph[b].push_back({a, i});
    }

    long long dist[N + 1];
    fill(dist, dist + N + 1, 1e13);

    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        ll time = -pq.top().first;
        pq.pop();

        if (dist[cur] < time)
            continue;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int period = graph[cur][i].second;

            // time = kN + period -> cross_time =  kM + period
            // time = kN + period + 1 -> cross_time =  (k+1)M + period
            ll cross_time = period;
            if (time > period)
                cross_time = period + (((time - period - 1) / M) + 1) * M;
            if (dist[next] > cross_time)
            {
                dist[next] = cross_time;
                pq.push({-cross_time, next});
            }
        }
    }

    cout << dist[N] << '\n';
}
