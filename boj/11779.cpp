#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

const int INF = 0x3f3f3f3f;

int N, M;
int start, fin;
vector<pair<int, int>> edge[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[1001];
int before[1001];
stack<int> route;

void Dijkstra(int start, int fin)
{
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (cur_cost > dist[cur_node])
            continue;

        for (int i = 0; i < edge[cur_node].size(); i++)
        {
            int next_node = edge[cur_node][i].first;
            int next_dist = edge[cur_node][i].second;
            if (dist[next_node] > cur_cost + next_dist)
            {
                dist[next_node] = cur_cost + next_dist;
                before[next_node] = cur_node;
                pq.push({dist[next_node], next_node});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // get input
    cin >> N >> M;
    int from, to, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        edge[from].push_back({to, cost});
    }
    cin >> start >> fin;

    fill(dist, dist + N + 1, INF);
    dist[start] = 0;

    // solve
    Dijkstra(start, fin);

    // print answer
    cout << dist[fin] << '\n';

    int cur = fin;
    while (cur)
    {
        route.push(cur);
        cur = before[cur];
    }
    cout << route.size() << '\n';
    while (!route.empty())
    {
        cout << route.top() << ' ';
        route.pop();
    }
    cout << '\n';
}

/*
다익스트라 + 경로 추적.
새로운 간선을 우선순위 큐에 넣을 때 새로운 정점의
직전 정점 정보를 같이 갱신해뒀다가 마지막에 도착점부터
시작점까지 거꾸로 추적해서 출력한다.
*/