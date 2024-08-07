#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
int parent[10001];
vector<pair<int, pair<int, int>>> edges;

int getParent(int node)
{
    if (parent[node] == node)
        return node;
    else
        return parent[node] = getParent(parent[node]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;

    // get input
    int node1, node2, cost;
    for (int i = 0; i < E; i++)
    {
        cin >> node1 >> node2 >> cost;
        edges.emplace_back(make_pair(cost, make_pair(node1, node2)));
    }

    // sort edges
    sort(edges.begin(), edges.end());

    // setting for union-find
    for (int i = 1; i <= V; i++)
        parent[i] = i;

    // Kruskal's algorithm
    long long sum = 0;
    for (int i = 0; i < E; i++)
    {
        cost = edges[i].first;
        node1 = edges[i].second.first;
        node2 = edges[i].second.second;

        if (getParent(node1) != getParent(node2))
        {
            parent[getParent(node2)] = getParent(node1);
            sum += cost;
        }
    }

    // print result
    cout << sum;
}