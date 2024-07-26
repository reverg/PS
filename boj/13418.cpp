#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;
int A, B, C;
vector<tuple<int, int, int>> edges;
int p[1002];

int find(int x)
{
    if (p[x] == -1)
        return x;
    else
        return p[x] = find(p[x]);
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return false;
    else
    {
        if (p[u] < p[v])
            p[v] = u;
        else
            p[u] = v;

        return true;
    }
}

int kruskal()
{
    fill(p, p + N + 2, -1);

    int sum = 0;
    int cnt = 0;
    for (auto [c, u, v] : edges)
    {
        if (!merge(u, v))
            continue;
        cnt++;
        sum += c;

        if (cnt == N) // 0~N번 건물
            break;
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M + 1; i++)
    {
        cin >> A >> B >> C;
        edges.push_back({(C == 0), A, B}); // 0이 오르막길
    }

    sort(edges.begin(), edges.end());
    int min_up = kruskal();

    sort(edges.rbegin(), edges.rend());
    int max_up = kruskal();

    cout << (max_up * max_up) - (min_up * min_up) << '\n';
}

/*
크루스칼을 2번 사용. 오름차순으로 정렬하면 최소 피로도, 내림차순으로 정렬하면 최대 피로도 나옴
*/
