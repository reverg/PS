#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<int>> parent;
vector<int> depth;

int initialize(int n)
{
    adj.clear();
    parent.clear();
    depth.clear();
    adj.resize(n + 1);
    parent.resize(n + 1);
    depth.resize(n + 1, 0);

    int len = (int)ceil(log2(n));
    for (int i = 0; i <= n; i++)
        parent[i].resize(len, -1);

    return len;
}

int getRoot()
{
    int root = 0;

    for (int idx = 1; idx <= n; idx++)
        if (depth[idx] == 0)
            root = idx;

    return root;
}

void connection(int root, int len)
{
    // get first parent: use bfs
    queue<pair<int, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        int cur = q.front().first;
        int stk = q.front().second;
        depth[cur] = stk;
        q.pop();

        for (int next : adj[cur])
        {
            parent[next][0] = cur; // cur node is (2^0)th parent of next node
            q.push(make_pair(next, stk + 1));
        }
    }

    // get remained parts
    for (int k = 1; k < len; k++)
    {
        for (int cur = 1; cur <= n; cur++)
        {
            if (parent[cur][k - 1] != -1)
                // recursive: 2^k = 2^(k-1) + 2^(k-1)
                parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
        }
    }
}

int lca(int u, int v, int len)
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
        for (int i = len - 1; i >= 0; i--)
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

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        int len = initialize(n);

        for (int i = 0; i < n - 1; i++)
        {
            int from, to;
            cin >> from >> to;
            adj[from].emplace_back(to);
            depth[to]++;
        }

        int root = getRoot();

        connection(root, len);

        int u, v;
        cin >> u >> v;
        cout << lca(u, v, len) << '\n';
    }
}