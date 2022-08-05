#include <iostream>
#include <queue>
#include <vector>

#define INF 999999999

using namespace std;

int N, K;
int dist[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start)
{
    for (int i = 0; i <= 100000; i++)
        dist[i] = INF;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty())
    {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (cur_node * 2 <= 100000 && cur_cost < dist[cur_node * 2])
        {
            dist[cur_node * 2] = cur_cost;
            pq.push(make_pair(cur_cost, cur_node * 2));
        }
        if (cur_node - 1 >= 0 && cur_cost < dist[cur_node - 1])
        {
            dist[cur_node - 1] = cur_cost + 1;
            pq.push(make_pair(cur_cost + 1, cur_node - 1));
        }
        if (cur_node + 1 <= 100000 && cur_cost < dist[cur_node + 1])
        {
            dist[cur_node + 1] = cur_cost + 1;
            pq.push(make_pair(cur_cost + 1, cur_node + 1));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;
    dijkstra(N);
    cout << dist[K];
}