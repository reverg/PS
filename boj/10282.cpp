#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int N, D, C;
        cin >> N >> D >> C;

        vector<pair<int, int>> graph[N + 1];
        for (int i = 0; i < D; i++)
        {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }

        int dist[N + 1];
        fill(dist, dist + N + 1, INF);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[C] = 0;
        pq.push({0, C});

        while (!pq.empty())
        {
            auto [cur_time, cur_node] = pq.top();
            pq.pop();

            if (dist[cur_node] < cur_time)
                continue;

            for (int i = 0; i < graph[cur_node].size(); i++)
            {
                auto [next_node, next_dist] = graph[cur_node][i];
                int next_time = cur_time + next_dist;
                if (dist[next_node] > next_time)
                {
                    dist[next_node] = next_time;
                    pq.push({next_time, next_node});
                }
            }
        }

        int max_dist = 0;
        int hack_cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            if (dist[i] != INF)
            {
                hack_cnt++;
                if (dist[i] > max_dist)
                    max_dist = dist[i];
            }
        }

        cout << hack_cnt << ' ' << max_dist << '\n';
    }
}

/*
기본 다익스트라 문제. 솔직히 테스트케이스 N개짜리 문제는 좀 없앴으면 좋겠다...
*/