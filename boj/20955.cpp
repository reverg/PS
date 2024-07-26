#include <iostream>
#include <queue>

using namespace std;

int N, M;
vector<int> adj[100001];
bool visited[100001];

void dfs(int cur)
{
    if (visited[cur])
        return;

    visited[cur] = true;
    for (auto nxt : adj[cur])
        dfs(nxt);
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int groupCnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
            continue;

        dfs(i);
        groupCnt++;
    }

    // 연결그래프 만들고 남는 간선 끊기
    cout << (groupCnt - 1) + ((M + groupCnt - 1) - (N - 1)) << '\n';
}