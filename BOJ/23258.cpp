#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int dist[301][301][301];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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