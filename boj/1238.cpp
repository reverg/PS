#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int INF = 0x3f3f3f3f;

int N, M, X;
vector<pair<int, int>> edge[2][100001];
int dist[2][1001];

void dijkstra(int idx)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, X});

    while (!pq.empty())
    {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (cur_cost != dist[idx][cur_node])
            continue;

        for (int i = 0; i < edge[idx][cur_node].size(); i++)
        {
            int next_node = edge[idx][cur_node][i].first;
            int next_dist = edge[idx][cur_node][i].second;
            if (dist[idx][next_node] > cur_cost + next_dist)
            {
                dist[idx][next_node] = cur_cost + next_dist;
                pq.push({dist[idx][next_node], next_node});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;
    int from, to, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        edge[0][to].push_back({from, cost});
        edge[1][from].push_back({to, cost});
    }

    fill(dist[0], dist[0] + N + 1, INF);
    fill(dist[1], dist[1] + N + 1, INF);
    dist[0][X] = 0;
    dist[1][X] = 0;

    // Silver Cow Party!!!
    dijkstra(0);
    dijkstra(1);

    int max_dist = 0;
    for (int i = 1; i <= N; i++)
        max_dist = max(max_dist, dist[0][i] + dist[1][i]);
    cout << max_dist << '\n';
}

/*
플로이드를 돌려야하나...라는 생각을 아주 잠깐 할 수는 있겠으나
농장 하나로 갔다가 돌아오는 것이기 때문에 다익스트라로 충분하다.
파티한 농장에서 돌아오는건 기본 다익스트라로 가능하고,
파티한 농장으로 가는건 간선 방향을 다 뒤집어둔 상태로 파티 농장에서
다익스트라를 쓰면 각자의 농장에서 파티할 농장으로 가는 거리가 구해진다.
*/