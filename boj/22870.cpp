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
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int dijkstra(int start, int end)
{
    int dist[200001];

    fill(dist, dist + 200001, INF);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [cur_dist, cur_node] = pq.top();
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
                pq.push({ndist, next_node});
            }
            else if (dist[next_node] == ndist)
                pre[next_node] = min(pre[next_node], cur_node); // 사전순 경로 선택
        }
    }

    return dist[end];
}

void remove_path(int start, int fin)
{
    int cur = start;
    while (cur > 0)
    {
        used[cur] = true;
        cur = pre[cur];
    }

    used[start] = false;
    used[fin] = false;
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
    remove_path(S, E);

    // Dijkstra 2
    ans += dijkstra(S, E);

    cout << ans << '\n';
}

/*
사전순 경로 선택이 어렵다.
시작->도착으로 다익스트라를 돌리고 역추적을 하면 경로를
뒤에서 앞으로 생성하는 것이므로 사전순 정렬이 안된다.
경로를 뒤집어서, 즉 도착->시작으로 다익스트라를 돌리면
경로 역추적이 시작점에서 도착점 순서로 되므로 사전순 정렬이
된 경로를 얻을 수 있다. 이 아이디어를 제외하면 #5719와 유사.
*/