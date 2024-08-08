#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int N, M;
vector<pair<int, int>> graph[N + 1];
ll dist[N + 1];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // get input
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, i});
        graph[b].push_back({a, i});
    }
    fill(dist, dist + N + 1, 1e13);

    // dijkstra
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        ll time = pq.top().first;
        pq.pop();

        if (dist[cur] != time)
            continue;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int period = graph[cur][i].second;

            // time = kN + period -> cross_time = kM + period
            // time = kN + period + 1 -> cross_time = (k+1)M + period
            ll cross_time = period;
            if (time > period)
                cross_time = period + (((time - period - 1) / M) + 1) * M;
            if (dist[next] > cross_time)
            {
                dist[next] = cross_time;
                pq.push({cross_time, next});
            }
        }
    }

    // print answer
    cout << dist[N] << '\n';
}

/*
가중치가 동적으로 정해지는 다익스트라.
시간별로 계속 갈 수 있는지 확인하면 한 세월이 걸린다.
각각의 횡단보도 별로 현재 위치에서 건널 수 있는 다음 시간을
계산해 pq에 넣어주면 된다.
*/