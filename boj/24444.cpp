#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, R;
vector<vector<int>> node;
vector<bool> visited;
queue<int> q;
int cnt = 1;
int ans[200001];

void bfs(int R)
{
    visited[R] = true;
    q.push(R);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans[u] = cnt++;

        for (auto x : node[u])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> R;
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
    {
        sort(node[i].begin(), node[i].end());
        visited[i] = false;
    }

    bfs(R);

    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';
}