#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int parent[100000];
vector<pair<int, int>> coord[3];
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
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int x, y, z;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y >> z;
        coord[0].emplace_back(make_pair(x, i));
        coord[1].emplace_back(make_pair(y, i));
        coord[2].emplace_back(make_pair(z, i));
    }

    // corner case
    if (N <= 1)
    {
        cout << 0;
        return 0;
    }

    sort(coord[0].begin(), coord[0].end());
    sort(coord[1].begin(), coord[1].end());
    sort(coord[2].begin(), coord[2].end());

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < N - 1; i++)
        {
            int dist = coord[j][i + 1].first + -coord[j][i].first;
            edges.emplace_back(make_pair(dist, make_pair(coord[j][i].second, coord[j][i + 1].second)));
        }
    }

    sort(edges.begin(), edges.end());

    // setting for union-find
    for (int i = 0; i < N; i++)
        parent[i] = i;

    // Kruskal's algorithm
    long long sum = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int dist = edges[i].first;
        int star1 = edges[i].second.first;
        int star2 = edges[i].second.second;

        if (getParent(star1) != getParent(star2))
        {
            parent[getParent(star2)] = getParent(star1);
            sum += dist;
        }
    }

    // print result
    cout << sum;
}