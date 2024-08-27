class Solution
{
public:
    int ans = INT_MAX;

    void bfs(int src, vector<int> adj[], int n)
    {
        vector<int> distance(n, (1e9));
        vector<int> parent(n, -1);

        queue<int> q;
        distance[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto neigh : adj[node])
            {
                if (distance[neigh] == (int)(1e9))
                {
                    distance[neigh] = 1 + distance[node];
                    parent[neigh] = node;
                    q.push(neigh);
                }
                else if (parent[node] != neigh && parent[neigh] != node)
                    ans = min(ans, distance[neigh] + distance[node] + 1);
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>> &edges)
    {

        vector<int> adj[n + 1];
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            bfs(i, adj, n);
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};

/*
(Runtime, Memory) = (66.30%, 96.77%). #141 -> #142 -> #2360 -> #2608.
루프를 양쪽에서 돌다가 만나면 기록된 distance로 cycle 크기를 계산한다.
모든 점에서 하고 shortest라 가능한 풀이같다. longest를 구하려 했다가는 루프 밖에
붙은 꼬리에서 시작한 경우 이상한 값이 나왔을 것. 같은 루프를 여러 번 돌기 때문에
시간복잡도도 별로다. 최악의 경우 O(N^2).
*/