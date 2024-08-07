#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int v;
vector<pair<int, int>> graph[100001];
bool visited[100001];
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v;
    int x, y, dist;
    for (int i = 0; i < v; i++)
    {
        cin >> x;
        while (true)
        {
            cin >> y;
            if (y == -1)
                break;
            cin >> dist;
            graph[x].push_back(make_pair(y, dist));
        }
    }

    // get max_node from 1
    dfs(1, 0);
    max_dist = 0;
    memset(visited, 0, sizeof(visited));
    // get max_node' from max_node
    dfs(max_node, 0);

    cout << max_dist;
}

/*
#1967과 동일. 트리의 크기만 다르다.
*/