#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> node;
vector<bool> visited;
int cnt = -1; // 마지막에 전부 visited된 경우도 count 됨

void dfs(int R)
{
    visited[R] = true;
    cnt++;

    for (auto x : node[R])
    {
        if (visited[x] == false)
            dfs(x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    node.resize(N + 1);
    visited.resize(N + 1);

    int u, v;
    while (M--)
    {
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        visited[i] = false;

    dfs(1);

    cout << cnt;
}