#include <iostream>
#include <vector>
#include <algorithm>

#define HEIGHT 18 // ceil(log_2(n))

using namespace std;

int depth[100001];
int parent[100001][HEIGHT];
int min_road[100001][HEIGHT];
int max_road[100001][HEIGHT];
vector<pair<int, int>> adj[100001];
int n, m;

void findParent(int par, int cur, int cost, int dep)
{
    // DFS
    depth[cur] = dep;
    parent[cur][0] = par;
    min_road[cur][0] = max_road[cur][0] = cost;

    for (auto next : adj[cur])
    {
        if (next.first != par)
            findParent(cur, next.first, next.second, dep + 1);
    }
}

void connection()
{
    for (int k = 1; k < HEIGHT; k++)
    {
        for (int cur = 1; cur <= n; cur++)
        {
            if (parent[cur][k - 1] != 0)
            {
                // recursive: 2^k = 2^(k-1) + 2^(k-1)
                parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
                min_road[cur][k] = min(min_road[parent[cur][k - 1]][k - 1], min_road[cur][k - 1]);
                max_road[cur][k] = max(max_road[parent[cur][k - 1]][k - 1], max_road[cur][k - 1]);
            }
        }
    }
}

pair<int, int> findRoad(int u, int v)
{
    int min_res = 1000001, max_res = 0;

    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];
    for (int i = 0; diff != 0; i++)
    {
        if (diff & 1)
        {
            // must sum before change node
            min_res = min(min_res, min_road[u][i]);
            max_res = max(max_res, max_road[u][i]);
            u = parent[u][i];
        }

        diff = diff >> 1;
    }

    if (u != v)
    {
        for (int i = HEIGHT - 1; i >= 0; i--)
        {
            if (parent[u][i] != 0 && parent[u][i] != parent[v][i])
            {
                min_res = min(min_res, min_road[u][i]);
                min_res = min(min_res, min_road[v][i]);

                max_res = max(max_res, max_road[u][i]);
                max_res = max(max_res, max_road[v][i]);

                u = parent[u][i];
                v = parent[v][i];
            }
        }
        min_res = min(min_res, min_road[u][0]);
        min_res = min(min_res, min_road[v][0]);

        max_res = max(max_res, max_road[u][0]);
        max_res = max(max_res, max_road[v][0]);
    }

    return make_pair(min_res, max_res);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin >> n;
    fill(parent[0], parent[0] + (sizeof(parent) / sizeof(int)), 0);
    fill(min_road[0], min_road[0] + (sizeof(min_road) / sizeof(int)), 1000001);
    fill(max_road[0], max_road[0] + (sizeof(max_road) / sizeof(int)), 0);

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
                get
        }
        cin >> u >> v;
        pair<int, int> ans = findRoad(u, v);
        cout << ans.first << ' ' << ans.second << '\n';
    }
}