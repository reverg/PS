#include <iostream>
#include <queue>

using namespace std;

int N, M;
vector<int> adj[100001];
bool visited[100001];

void dfs(int cur)
{
    if (visited[cur])
        return;

    visited[cur] = true;
    for (auto nxt : adj[cur])
        dfs(nxt);
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int groupCnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
            continue;

        dfs(i);
        groupCnt++;
    }

    // 연결그래프 만들고 남는 간선 끊기
    cout << (groupCnt - 1) + ((M + groupCnt - 1) - (N - 1)) << '\n';
}

/*
Tree에서 E = V-1임을 활용하는 문제. 분리된 집합들 개수를
개수를 세서 하나로 이어주고 남는 간선은 다 끊어주면 된다.
Union-find로 cycle 판별하며 푸는 것도 가능.
노드를 1번씩 방문하므로 O(N+M)으로 처리된다.
*/