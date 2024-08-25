#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef long long ll;
typedef tuple<ll, int, int> tlii;

int N, M, K;
vector<pair<int, ll>> graph[10001];
ll dist[10001][21];
priority_queue<tlii, vector<tlii>, greater<tlii>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // get input
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

    // dijkstra
    pq.push({0, 1, 0});
    dist[1][0] = 0;

    ll ans = -1;
    while (!pq.empty())
    {
        ll cur_time;
        int cur_node, cur_k;
        tie(cur_time, cur_node, cur_k) = pq.top();
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
                pq.push({next_time, next_node, cur_k});
            }

            if (cur_k < K && dist[next_node][cur_k + 1] > cur_time)
            {
                dist[next_node][cur_k + 1] = cur_time;
                pq.push({cur_time, next_node, cur_k + 1});
            }
        }
    }

    cout << ans << '\n';
}

/*
포장한 도로의 개수를 같이 넣는 다익스트라. 정점이 (정점 번호)가 아니라
(정점번호, 남은 포장 횟수)라고 생각해도 무방하다. priority_queue에서 시간이
가장 짧은 것을 계속 뽑아주니까 포장한 개수에 상관 없이 최단 시간이 나온다.
*/