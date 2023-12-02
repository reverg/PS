#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int parent[1001];
vector<pair<double, double>> stars;
vector<pair<double, pair<int, int>>> edges;
vector<pair<double, pair<int, int>>> connected;

double getDistance(pair<double, double> star1, pair<double, double> star2)
{
    double x_dist = star1.first - star2.first;
    double y_dist = star1.second - star2.second;
    return sqrt(x_dist * x_dist + y_dist * y_dist);
}

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

    cin >> N >> M;

    // setting for union-find
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    // get input
    double x, y;
    stars.emplace_back(make_pair(0, 0));
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        stars.emplace_back(make_pair(x, y));
    }
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        if (getParent(x) != getParent(y))
            parent[getParent(x)] = getParent(y);
    }

    // corner case
    if (N <= 1)
    {
        cout << 0;
        return 0;
    }

    // generate edges
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            edges.emplace_back(make_pair(getDistance(stars[i], stars[j]), make_pair(i, j)));

    // sort edges
    sort(edges.begin(), edges.end());

    // Kruskal's algorithm
    double sum = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        double dist = edges[i].first;
        int star1 = edges[i].second.first;
        int star2 = edges[i].second.second;

        if (getParent(star1) != getParent(star2))
        {
            parent[getParent(star2)] = getParent(star1);
            sum += dist;
        }
    }

    // print result
    printf("%.2lf", sum);
}