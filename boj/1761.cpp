#include <iostream>
#include <vector>
#include <cstring>

#define MAX 17 // ceil(log_2(n))

using namespace std;

int depth[40001];
int parent[40001][MAX];
int dist[40001][MAX];
vector<pair<int, int>> adj[40001];
int n, m;

void findParent(int par, int cur, int cost, int dep)
{
    // DFS
    depth[cur] = dep;
    parent[cur][0] = par;
    dist[cur][0] = cost;

    for (auto next : adj[cur])
    {
        if (next.first != par)
            findParent(cur, next.first, next.second, dep + 1);
    }
}

void connection()
{
    for (int k = 1; k < MAX; k++)
    {
        for (int cur = 1; cur <= n; cur++)
        {
            if (parent[cur][k - 1] != 0)
            {
                // recursive: 2^k = 2^(k-1) + 2^(k-1)
                parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
                dist[cur][k] = dist[cur][k - 1] + dist[parent[cur][k - 1]][k - 1];
            }
        }
    }
}

int getDistance(int u, int v)
{
    int sum = 0;

    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];
    for (int i = 0; diff != 0; i++)
    {
        if (diff & 1)
        {
            // must sum before change node
            sum += dist[u][i];
            u = parent[u][i];
        }

        diff = diff >> 1;
    }

    if (u != v)
    {
        for (int i = MAX - 1; i >= 0; i--)
        {
            if (parent[u][i] != 0 && parent[u][i] != parent[v][i])
            {
                sum += dist[u][i] + dist[v][i];
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        sum += dist[u][0] + dist[v][0];
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin >> n;
    memset(parent, 0, sizeof(parent));
    memset(dist, 0, sizeof(dist));

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
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        cout << getDistance(u, v) << '\n';
    }
}