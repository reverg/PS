#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef long long ll;

vector<pair<int, ll>> graph[10001];
ll dist[10001][21];
priority_queue<tuple<ll, int, int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        ll cost;
        cin >> a >> b >> cost;
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= K; j++)
            dist[i][j] = 0x3f3f3f3f3f3f3f3fLL;

    pq.push({0, 1, 0});
    dist[1][0] = 0;

    ll ans = -1;
    while (!pq.empty())
    {
        ll cur_time = -get<0>(pq.top());
        int cur_node = get<1>(pq.top());
        int cur_k = get<2>(pq.top());
        pq.pop();

        if (cur_node == N)
        {
            ans = cur_time;
            break;
        }

        if (dist[cur_node][cur_k] < cur_time)
            continue;

        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int next_node = graph[cur_node][i].first;
            ll cost = graph[cur_node][i].second;

            ll next_time = cur_time + cost;
            if (dist[next_node][cur_k] > next_time)
            {
                dist[next_node][cur_k] = next_time;
                pq.push({-next_time, next_node, cur_k});
            }

            if (cur_k < K && dist[next_node][cur_k + 1] > cur_time)
            {
                dist[next_node][cur_k + 1] = cur_time;
                pq.push({-cur_time, next_node, cur_k + 1});
            }
        }
    }

    cout << ans << '\n';
}