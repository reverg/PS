#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, M;
    cin >> N >> K >> M;

    vector<int> graph[101001];
    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            int station;
            cin >> station;
            graph[N + i].push_back(station);
            graph[station].push_back(N + i);
        }
    }

    queue<int> q;
    int dist[101001] = {0};
    dist[1] = 1;
    q.push(1);

    int ans = -1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == N)
        {
            ans = dist[cur];
            break;
        }

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];

            if (dist[next] == 0)
            {
                if (next > N)
                    dist[next] = dist[cur];
                else
                    dist[next] = dist[cur] + 1;

                q.push(next);
            }
        }
    }

    cout << ans << '\n';
}