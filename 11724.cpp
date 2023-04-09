#include <iostream>
#include <vector>
#include <queue>

std::vector<int> graph[10001];
bool visited[1001] = {false};

void BFS(int start)
{
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            if (!visited[graph[cur][i]])
            {
                visited[graph[cur][i]] = true;
                q.push(graph[cur][i]);
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int scc = 0;
    int N, M, u, v;
    std::cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            BFS(i);
            scc++;
        }
    }

    std::cout << scc << '\n';
}