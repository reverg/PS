#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> node;
vector<bool> visited;
queue<int> q;

void dfs(int V)
{
    visited[V] = true;
    cout << V << ' ';

    for (auto x : node[V])
    {
        if (!visited[x])
            dfs(x);
    }
}

void bfs(int V)
{
    visited[V] = true;
    q.push(V);

    while (!q.empty())
    {
        int u = q.front();
        cout << u << ' ';
        q.pop();

        for (auto x : node[u])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> V;
    node.resize(N + 1);
    visited.resize(N + 1);

    int u, v;
    while (M--)
    {
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        sort(node[i].begin(), node[i].end());

    for (int i = 1; i <= N; i++)
        visited[i] = false;
    dfs(V);
    cout << '\n';

    for (int i = 1; i <= N; i++)
        visited[i] = false;
    bfs(V);
}