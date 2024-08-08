#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int N, M, S, D;
int graph[500][500];
int dist[500];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
vector<int> prev_node[500];

void dijkstra()
{
    fill(dist, dist + N, INF);
    dist[S] = 0;

    pq.push({0, S});

    while (!pq.empty())
    {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (dist[cur_node] < cur_dist)
            continue;

        for (int next_node = 0; next_node < N; next_node++)
        {
            int cost = graph[cur_node][next_node];
            if (cost == INF)
                continue;

            int ndist = dist[cur_node] + cost;
            if (dist[next_node] > ndist)
            {
                prev_node[next_node].clear();
                prev_node[next_node].push_back(cur_node);
                dist[next_node] = ndist;
                pq.push({ndist, next_node});
            }
            else if (dist[next_node] == ndist)
            {
                prev_node[next_node].push_back(cur_node);
            }
        }
    }
}

void remove_path()
{
    // using prev node info,
    // remove path by bfs
    queue<int> q;
    bool visited[500] = {false};
    visited[D] = true;
    q.push(D);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int p : prev_node[cur])
        {
            graph[p][cur] = INF;

            if (!visited[p])
            {
                visited[p] = true;
                q.push(p);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> ans;

    while (true)
    {
        // get input
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        cin >> S >> D;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                graph[i][j] = INF;
        for (int i = 0; i < M; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            graph[u][v] = p;
        }
        for (int i = 0; i < 500; i++)
            prev_node[i].clear();

        // Dijkstra 1
        dijkstra();

        // remove shortest paths
        remove_path();

        // Dijkstra 2
        dijkstra();
        int almost_shortest_distance = dist[D];

        // push answer
        if (almost_shortest_distance == 1e9)
            ans.push_back(-1);
        else
            ans.push_back(almost_shortest_distance);
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
}

/*
다익스트라 + 경로 추적 + 역방향 BFS + 다익스트라.
구현이 좀 성가시긴 한데 아이디어는 익숙한 것들이다.
*/