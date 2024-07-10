#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

struct Edge
{
    int start;
    int end;
    int length;
};

int main()
{
    int N, M;
    cin >> N >> M;

    int dist[201][201];
    for (int i = 1; i <= 200; i++)
        for (int j = 1; j <= 200; j++)
            dist[i][j] = (i == j ? 0 : INF);

    vector<Edge> edges;
    for (int i = 0; i < M; i++)
    {
        int s, e, l;
        cin >> s >> e >> l;
        dist[s][e] = min(dist[s][e], l);
        dist[e][s] = min(dist[e][s], l);
        edges.push_back(Edge{s, e, l});
    }

    for (int mid = 1; mid <= N; mid++)
        for (int from = 1; from <= N; from++)
            for (int to = 1; to <= N; to++)
                dist[from][to] = min(dist[from][to], dist[from][mid] + dist[mid][to]);

    int min_ignite_time = INF;
    for (int i = 1; i <= N; i++)
    {
        int ignite_time = 0;
        for (int j = 0; j < M; j++)
            ignite_time = max(ignite_time, dist[i][edges[j].start] + dist[i][edges[j].end] + edges[j].length);

        min_ignite_time = min(min_ignite_time, ignite_time);
    }

    cout << min_ignite_time / 2 << '.' << (min_ignite_time % 2) * 5 << '\n';
}