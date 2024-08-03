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

void Dijkstra()
{
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

        if (cur_node == D)
            continue;
        if (dist[cur_node][cur_roads] < cur_dist)
            continue;

        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int next_node = graph[cur_node][i].first;
            int new_dist = cur_dist + graph[cur_node][i].second;

            if (dist[next_node][cur_roads + 1] > new_dist)
            {
                dist[next_node][cur_roads + 1] = new_dist;
                pq.push({-new_dist, next_node, cur_roads + 1});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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

    Dijkstra();

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

/*
O(NMlogN + NK) 풀이. 거쳐간 도로의 개수를 같이 가지는 2차원 DP를 사용했다.
BFS를 사용한 풀이보다 속도 100배, 메모리 8배 정도 안 좋지만, 거쳐간 도로
개수가 중요하단 것을 빠르게 못 깨달으면 이쪽이 더 직관적인 풀이같긴 하다.
끝의 O(NK)도 BFS때와 달리 NK개 모두 확인해서 정말 느리다.
*/