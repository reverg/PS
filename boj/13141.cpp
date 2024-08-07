#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M;
vector<Edge> edges;

struct Edge
{
    int start;
    int end;
    int length;
};

int main()
{
    cin >> N >> M;

    int dist[201][201];
    for (int i = 1; i <= 200; i++)
        for (int j = 1; j <= 200; j++)
            dist[i][j] = (i == j ? 0 : INF);

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

/*
어떤 간선을 다 태우고 싶으면 (불 붙인 곳 -> 시작점 -> 간선 -> 끝점 -> 불 붙인 곳)을
다 돌고 오면 된다. 불이 양쪽에서 가므로 특정 간선을 태우는데 걸리는 시간은 이것의 절반.
45행에서 가장 오랜 시간이 걸리는 간선을 태우려면 얼마나 걸리는지 확인하고, 그 절반을
50행에서 출력한다.
*/