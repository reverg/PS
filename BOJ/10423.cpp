#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M, K;
vector<int> p(1001, -1);
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
        return 0;
    
    if (p[u] < p[v])
        p[v] = u;
    else
        p[u] = v;
    return 1;
}

int main()
{
    cin >> N >> M >> K;

    int cnt = 0;
    for (int i = 0; i < K; i++)
    {
        int pikachu;
        cin >> pikachu;
        p[pikachu] = 0;
        cnt++;
    }

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    int ans = 0;
    for (auto [w, u, v] : edges)
    {
        if (!merge(u, v))
            continue;
        ans += w;
        cnt++;
        if (cnt == N)
            break;
    }

    cout << ans << '\n';
}

/*
크루스칼 알고리즘.
새로운 정점을 하나 만들어서 발전소를 모두 merge하고 시작.
공통 부모가 생겨서 발전소에 여러 번 연결되지 않음. (여러 번 연결되면 2번 이상 merge 됨)
M+1개 노드에서 MST 찾으면 됨.
*/