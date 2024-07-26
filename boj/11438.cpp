#include <iostream>
#include <vector>
#include <cstring>

#define MAX 18 // ceil(log_2(n))

using namespace std;

int parent[100001][MAX];
int depth[100001];
vector<vector<int>> adj;
int n, m;

void dfs(int cur)
{
    for (int next : adj[cur])
    {
        if (depth[next] == -1)
        {
            parent[next][0] = cur; // cur node is (2^0)th parent of next node
            depth[next] = depth[cur] + 1;
            dfs(next);
        }
    }
}

void connection()
{
    for (int k = 1; k < MAX; k++)
    {
        for (int cur = 1; cur <= n; cur++)
        {
            if (parent[cur][k - 1] != -1)
                // recursive: 2^k = 2^(k-1) + 2^(k-1)
                parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];
    for (int i = 0; diff != 0; i++)
    {
        if (diff & 1)
            u = parent[u][i];

        diff = diff >> 1;
    }

    if (u != v)
    {
        for (int i = MAX - 1; i >= 0; i--)
        {
            if (parent[u][i] != -1 && parent[u][i] != parent[v][i])
            {
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        u = parent[u][0];
    }

    return u;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin >> n;
    adj.resize(n + 1);
    memset(depth, -1, sizeof(depth));
    memset(parent, -1, sizeof(parent));
    depth[1] = 0; // root

    int from, to;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> from >> to;
        adj[from].emplace_back(to);
        adj[to].emplace_back(from);
    }

    dfs(1);

    connection();

    cin >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}