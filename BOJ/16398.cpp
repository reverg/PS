#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N;
vector<tuple<int, int, int>> edges;
int parent[1001];

int find(int x)
{
    if (parent[x] < 0)
        return x;
    else
        return parent[x] = find(parent[x]);
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return false;
    else
    {
        if (parent[u] == parent[v])
            parent[u]--;

        if (parent[u] < parent[v])
            parent[v] = u;
        else
            parent[u] = v;
        return true;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    fill(parent, parent + N, -1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int c;
            cin >> c;
            if (i == j)
                continue;
            edges.push_back({c, i, j});
        }
    }

    sort(edges.begin(), edges.end());

    int cnt = 0;
    long long ans = 0;
    for (auto e : edges)
    {
        int c, u, v;
        tie(c, u, v) = e;

        if (!merge(u, v))
            continue;

        ans += c;
        cnt++;

        if (cnt == N - 1)
            break;
    }

    cout << ans << '\n';
}

/*
크루스칼 알고리즘
*/