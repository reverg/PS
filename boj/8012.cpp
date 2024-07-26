#include <iostream>
#include <vector>
#include <cstring>

#define HEIGHT 14 // ceil(log_2(n))

using namespace std;

int depth[30001];
int parent[30001][HEIGHT];
vector<int> adj[30001];
int n, m;

void findParent(int par, int cur, int dep)
{
    // DFS
    depth[cur] = dep;
    parent[cur][0] = par;

    for (auto next : adj[cur])
    {
        if (next != par)
            findParent(cur, next, dep + 1);
    }
}

void connection()
{
    for (int k = 1; k < HEIGHT; k++)
    {
        for (int cur = 1; cur <= n; cur++)
        {
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

        diff >>= 1;
    }

    if (u != v)
    {
        for (int i = HEIGHT - 1; i >= 0; i--)
        {
            if (parent[u][i] != parent[v][i])
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
    memset(depth, -1, sizeof(depth));

    int from, to;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> from >> to;
        adj[from].emplace_back(to);
        adj[to].emplace_back(from);
    }

    findParent(0, 1, 0);
    connection();

    long long ans = 0;
    cin >> m;
    cin >> from;
    for (int i = 0; i < m - 1; i++)
    {
        cin >> to;
        ans += (depth[from] + depth[to] - 2 * depth[lca(from, to)]);
        from = to;
    }

    cout << ans;
}