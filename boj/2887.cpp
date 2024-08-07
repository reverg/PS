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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int x, y, z;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y >> z;
        coord[0].emplace_back(make_pair(x, i));
        coord[1].emplace_back(make_pair(y, i));
        coord[2].emplace_back(make_pair(z, i));
    }

    sort(coord[0].begin(), coord[0].end());
    sort(coord[1].begin(), coord[1].end());
    sort(coord[2].begin(), coord[2].end());

    // edge에 인접한 행성들의 정보만 저장
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

/*
크루스칼 알고리즘.
모든 간선의 정보를 저장하면 최악의 경우 50억개 저장해야 한다.
가까운 행성을 놔두고 먼 행성과 연결할 일은 없으므로 x, y, z 좌표에 대해 인접한 행성들만 고려해주면 된다.
x, y, z 좌표를 따로 저장해 정렬해두고 이웃하는 것들만 고려해 MST를 구축하면 정답이다.
*/