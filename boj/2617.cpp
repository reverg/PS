#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> graph, int start)
{
    int cnt = -1;
    queue<int> q;
    bool visited[graph.size()] = {false};
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> heavier(N + 1);
    vector<vector<int>> lighter(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        heavier[u].push_back(v);
        lighter[v].push_back(u);
    }

    int ans = 0;
    int half = (N + 1) / 2;

    for (int i = 1; i <= N; i++)
    {
        int heavy = bfs(heavier, i);
        int light = bfs(lighter, i);

        if (heavy >= half || light >= half)
            ans++;
    }

    cout << ans << '\n';
}