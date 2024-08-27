class Solution
{
public:
    void dfs(vector<vector<int>> &graph, vector<int> &visited, int vertice,
             int parent, int length, int &cycle)
    {
        if (cycle == 3)
            return;

        visited[vertice] = length++;
        for (int next : graph[vertice])
        {
            if (next == parent)
                continue;
            if (visited[next] > length)
                dfs(graph, visited, next, vertice, length, cycle);
            if ((length - visited[next]) > 1)
                cycle = min(cycle, (length - visited[next]));
        }
    }

    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        vector<int> visited(n, 1001);
        vector<vector<int>> graph(n);
        int minLength = 1001;

        for (vector<int> &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (minLength == 3)
                break;
            if (visited[i] == 1001)
                dfs(graph, visited, i, -1, 0, minLength);
        }

        return minLength == 1001 ? -1 : minLength;
    }
};

/*
(Runtime, Memory) = (96.41%, 96.89%). #141 -> #142 -> #2360 -> #2608.
인접한 정점 중에 자기가 직전에 지나친 정점이 아닌 것이 있으면 사이클이란게 핵심.
근데 세부 처리가 힘들다... 베낀 코드인데 왜 되는지 솔직히 잘 모르겠다...
*/