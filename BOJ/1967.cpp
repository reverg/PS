#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int v;
vector<pair<int, int>> graph[10001];
bool visited[10001];
int max_dist = 0;
int max_node = 0;

void dfs(int start, int dist)
{
    visited[start] = true;
    if (max_dist < dist)
    {
        max_dist = dist;
        max_node = start;
    }

    for (int i = 0; i < graph[start].size(); i++)
    {
        if (!visited[graph[start][i].first])
            dfs(graph[start][i].first, graph[start][i].second + dist);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> v;
    int x, y, dist;
    for (int i = 0; i < v - 1; i++)
    {
        cin >> x >> y >> dist;
        graph[x].push_back(make_pair(y, dist));
        graph[y].push_back(make_pair(x, dist));
    }

    // get max_node from 1
    dfs(1, 0);
    max_dist = 0;
    memset(visited, 0, sizeof(visited));
    // get distance to max_node' from max_node
    dfs(max_node, 0);

    cout << max_dist;
}