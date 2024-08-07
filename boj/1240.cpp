// reference: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x19/solutions/1240.cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> adj[1001];
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    while (M--)
    {
        int u, v;
        cin >> u >> v;

        queue<pair<int, int>> q;
        vector<bool> visited(N + 1);
        q.push({u, 0});
        visited[u] = true;

        while (!q.empty())
        {
            auto [cur, cdist] = q.front();
            q.pop();

            if (cur == v)
            {
                cout << cdist << '\n';
                break;
            }
            for (auto [next, ndist] : adj[cur])
            {
                if (visited[next])
                    continue;
                visited[next] = true;
                q.push({next, cdist + ndist});
            }
        }
    }
}

/*
O(NM) 풀이. N, M이 1000 이하라 매번 해도 시간이 충분하다.
미리 N개의 점에 대해 거리를 다 저장해놓고 M개의 쿼리를
수행하는 O(N^2 + M) 풀이도 가능하다.
*/