#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int dist[301][301][301];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> dist[i][j][0];
            if (i != j && dist[i][j][0] == 0)
                dist[i][j][0] = INF;
        }
    }

    for (int mid = 1; mid <= N; mid++)
        for (int from = 1; from <= N; from++)
            for (int to = 1; to <= N; to++)
                dist[from][to][mid] = min(dist[from][to][mid - 1], dist[from][mid][mid - 1] + dist[mid][to][mid - 1]);

    for (int i = 0; i < Q; i++)
    {
        int c, s, e;
        cin >> c >> s >> e;
        cout << ((dist[s][e][c - 1] != INF) ? dist[s][e][c - 1] : -1) << '\n';
    }
}

/*
최대 물방울이 C 이하로 가는 최단거리
= 최대 물방울이 C-1인 지점을 거쳐가는 거리와 직행으로 가는 거리 중 작은 값
mid 값을 늘려가면서 계산하므로 필요한 값은 이전에 계산되어 있다.
*/