#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijk_pq;
priority_queue<int> city_heap[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dijk_pq.push({0, 1});
    city_heap[1].push(0);

    while (!dijk_pq.empty())
    {
        int cur_dist = dijk_pq.top().first;
        int cur_city = dijk_pq.top().second;
        dijk_pq.pop();

        if (city_heap[cur_city].top() < cur_dist)
            continue;

        for (int i = 0; i < graph[cur_city].size(); i++)
        {
            int next_city = graph[cur_city][i].first;
            int next_dist = cur_dist + graph[cur_city][i].second;

            if (city_heap[next_city].size() < K)
            {
                city_heap[next_city].push(next_dist);
                dijk_pq.push({next_dist, next_city});
            }
            else
            {
                if (city_heap[next_city].top() > next_dist)
                {
                    city_heap[next_city].pop();
                    city_heap[next_city].push(next_dist);
                    dijk_pq.push({next_dist, next_city});
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << (city_heap[i].size() == K ? city_heap[i].top() : -1) << '\n';
}