#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define INF 1e9

using namespace std;

int N, M, K, S, D;
vector<pair<int, int>> graph[1001];
int tax[30001];
int dist[1001];
vector<pair<int, int>> road;

void bfs()
{
    for (int i = 0; i <= 1000; i++)
        dist[i] = INF;
    dist[S] = 0;

    queue<tuple<int, int, int>> q;
    q.push({0, S, 0});
    while (!q.empty())
    {
        auto [cur_dist, cur_node, cur_roads] = q.front();
        q.pop();

        if (cur_node == D)
        {
            road.emplace_back(cur_dist, cur_roads);
            continue;
        }

        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int next_node = graph[cur_node][i].first;
            int new_dist = cur_dist + graph[cur_node][i].second;

            if (dist[next_node] <= new_dist)
                continue;

            dist[next_node] = new_dist;
            q.push({new_dist, next_node, cur_roads + 1});
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

    bfs();

    for (int k = 0; k <= K; k++)
    {
        int min_dist = INF;
        for (auto &[dist, road_num]: road)
        {
            dist += tax[k] * road_num;
            min_dist = min(min_dist, dist);
        }
        cout << min_dist << '\n';
    }
}

/*
O(NM + NK) 풀이. 거쳐하는 도로 개수가 증가하는 순서로 탐색되므로
2차원 배열을 사용할 필요가 없다. 어차피 도로 개수가 늘어나면 세금을
더 많이 내야 하기 때문. dist 배열이 갱신되는 것은 도로 개수가
늘어났지만 시간은 감소한 경우이다. 목표 지점에 도착한 경우만 따로
벡터로 저장했다가 시간을 구해주면 된다.
*/