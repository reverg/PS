#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int main()
{
    int N, M, T;
    cin >> N >> M >> T;

    int height[301][301] = {0};
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            height[i][j] = (i == j ? 0 : INF);

    for (int i = 0; i < M; i++)
    {
        int u, v, h;
        cin >> u >> v >> h;
        height[u][v] = h;
    }

    for (int mid = 1; mid <= N; mid++)
        for (int from = 1; from <= N; from++)
            for (int to = 1; to <= N; to++)
                height[from][to] = min(height[from][to], max(height[from][mid], height[mid][to]));

    for (int i = 0; i < T; i++)
    {
        int s, e;
        cin >> s >> e;
        if (height[s][e] != INF)
            cout << height[s][e] << '\n';
        else
            cout << -1 << '\n';
    }
}