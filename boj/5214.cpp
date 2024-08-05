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

/*
하이퍼튜브로 연결된 모든 노드를 간선으로 이으면
M*K*(K-1)개의 간선이 생기므로 메모리 초과가 난다.
하이퍼튜브 자체를 하나의 노드로 생각하자.
현재 구현에서는 graph[1] ~ graph[N]까지가 역,
graph[N+1] ~ graph[N+M]까지가 하이퍼튜브이다.
똑같이 bfs를 쓰되, 다음 노드가 하이퍼튜브이면 dist를
늘리지 않는 방식으로 거리를 구하면 된다. 하이퍼튜브가
역과 역을 잇는 유일한 방법이므로 역-튜브-역-튜브-역
형태로 이어진다.
*/