#include <iostream>
#include <vector>
#include <cstring>

#define HEIGHT 17 // ceil(log_2(n))

using namespace std;

int depth[100001];
int parent[100001][HEIGHT];
long long dist[100001];
vector<pair<int, int>> adj[100001];
int n, m;

void findParent(int par, int cur, long long cost, int dep)
{
    // DFS
    depth[cur] = dep;
    parent[cur][0] = par;
    dist[cur] = cost;

    for (auto next : adj[cur])
    {
        if (next.first != par)
            findParent(cur, next.first, next.second + dist[cur], dep + 1);
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

long long getDistance(int u, int v)
{
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}

int getNode(int u, int v, int k)
{
    int lca_node = lca(u, v);
    int upward = depth[u] - depth[lca_node];
    k--; // count itself
    if (k == upward)
        return lca_node;
    else if (k > upward)
    {
        int downward = depth[v] - depth[lca_node];
        k = upward + downward - k;
        swap(u, v);
    }

    for (int i = 0; k != 0; i++)
    {
        if (k & 1)
            u = parent[u][i];

        k >>= 1;
    }
    return u;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin >> n;
    memset(depth, -1, sizeof(depth));

    int from, to, cost;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> from >> to >> cost;
        adj[from].emplace_back(make_pair(to, cost));
        adj[to].emplace_back(make_pair(from, cost));
    }

    findParent(0, 1, 0, 0);
    connection();

    cin >> m;
    int q, u, v, k;
    for (int i = 0; i < m; i++)
    {
        cin >> q;
        switch (q)
        {
        case 1:
            cin >> u >> v;
            cout << getDistance(u, v) << '\n';
            break;
        case 2:
            cin >> u >> v >> k;
            cout << getNode(u, v, k) << '\n';
            break;
        }
    }
}