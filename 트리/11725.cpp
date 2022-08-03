#include <iostream>
#include <queue>

using namespace std;

int N;
vector<int> graph[100001];
int parent[100001];
queue<int> q;

void bfs(int root)
{
    q.push(root);
    parent[root] = root;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (parent[next] == 0)
            {
                parent[next] = cur;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int x, y;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    bfs(1);

    for (int i = 2; i <= N; i++)
        cout << parent[i] << '\n';
}