class Solution
{
public:
    int detectCycle(int cur, vector<int> &edges, vector<int> &visited,
                    vector<int> &dist)
    {
        int nxt = edges[cur];
        if (nxt == -1) // not a cycle
            return 0;

        if (!visited[nxt])
        {
            dist[nxt] = dist[cur] + 1;
            visited[nxt] = 1;
            int cycle = detectCycle(nxt, edges, visited, dist);
            dist[nxt] = 0;
            return cycle;
        }
        else if (dist[nxt] > 0)
        {
            return dist[cur] - dist[nxt] + 1;
        }

        return 0;
    }

    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<int> visited(n, 0);
        vector<int> dist(n, 0);

        int max_cycle_size = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            visited[i] = 1;
            dist[i] = 1;
            int cycle_size = detectCycle(i, edges, visited, dist);
            dist[i] = 0;
            if (max_cycle_size < cycle_size)
                max_cycle_size = cycle_size;
        }

        return (max_cycle_size > 0) ? max_cycle_size : -1;
    }
};

/*
(Runtime, Memory) = (99.53%, 85.01%). #141 -> #142 -> #2360 -> #2608.
DFS를 돌면서 이전에 거친 노드가 있으면 거리를 계산한다.
visited와 dist를 같이 사용해야 한다. 즉, 전체 작업에 대해 방문 여부를
체크하는 배열과 이번 작업에 대해 방문 여부를 체크하는 배열이 따로 있어야 한다.
visited만 쓰면 지금 DFS에서 나온 노드인지 아니면 이전에 확인된 노드인지 알 방법이
없고, dist만 쓰면 같은 루프를 여러 번 확인해서 O(N^2)에 동작할 수 있다.
시간, 공간 모두 O(N)에 풀리는 방법이다. 다만 dist를 매번 새로 만들면 TLE가 나서
백트래킹 느낌으로 처리해줘야 한다.
*/