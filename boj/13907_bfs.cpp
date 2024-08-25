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

            if (dist[next_node] > new_dist)
            {
                dist[next_node] = new_dist;
                q.push({new_dist, next_node, cur_roads + 1});
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

    bfs();

    for (int k = 0; k <= K; k++)
    {
        int min_dist = INF;
        for (auto &[dist, road_num] : road)
        {
            dist += tax[k] * road_num;
            min_dist = min(min_dist, dist);
        }
        cout << min_dist << '\n';
    }
}

/*
O(NM + NK) 풀이. #1162는 도로를 포장할지 포장하지 않을지 선택할 수 있었기 때문에
포장 개수가 많아지는 순서로 도착점에 도달하는게 아니었기 때문에 포장한 개수를 별도
차원으로 가지고 있었어야 했다. 하지만 이번 문제는 뒤에 도착한 경로가 무조건 이전에
도착한 경로보다 사용하는 도로 수가 많고, 세금이 양수이기 때문에 도로가 더 많으면
비용이 줄어서 거리를 갱신해야 하므로 다익스트라가 아닌 BFS를 사용해도 된다.
dist 배열이 갱신되는 것은  도로 개수가 늘어났지만 시간은 감소한 경우. 목표 지점에
도착한 경우만 따로 벡터로 저장했다가 시간을 구해주면 된다.

설명이 잘 이해되진 않겠지만 이런 경우에는 BFS로 푸는 것도 가능함을 알아두면 좋다.
핵심은 도로 개수가 늘어나면 무조건 거리가 감소해야 답이 될 가능성이 있다는 것이고,
BFS는 도로 개수가 늘어나는 순서로 탐색되니 거리를 비교해서 갱신하는게 유효하다는 것.
도로를 포장할지 선택 가능한 경우엔 큐 내부에서 도로 개수가 늘어나는 순이 유지되지 않는다.
*/