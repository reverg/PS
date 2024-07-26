// reference: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x1B/1368.cpp
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N;
vector<int> p(302, -1);
vector<tuple<int, int, int>> edges;

int find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;

    if (p[u] < p[v])
        p[v] = u;
    else
        p[u] = v;
    return true;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int w;
        cin >> w;
        edges.push_back({w, N, i});
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int w;
            cin >> w;
            if (i == j)
                continue;
            edges.push_back({w, i, j});
        }
    }

    sort(edges.begin(), edges.end());

    int cnt = 0;
    int ans = 0;
    for (auto [c, u, v] : edges)
    {
        if (!merge(u, v))
            continue;
        ans += c;
        cnt++;
        if (cnt == N)
            break;
    }

    cout << ans << '\n';
}

/*
크루스칼 알고리즘.
새로운 정점을 하나 만들고 각 우물을 파는 비용을 간선으로 갖게 하면 됨.
*/