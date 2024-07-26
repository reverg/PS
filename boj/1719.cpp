#include <iostream>

#define INF 1e9

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int dist[201][201] = {0};
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dist[i][j] = (i == j ? 0 : INF);

    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        dist[from][to] = cost;
        dist[to][from] = cost;
    }

    int route[201][201];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            route[i][j] = j;

    for (int mid = 1; mid <= N; mid++)
    {
        for (int from = 1; from <= N; from++)
        {
            for (int to = 1; to <= N; to++)
            {
                if (dist[from][to] > dist[from][mid] + dist[mid][to])
                {
                    dist[from][to] = dist[from][mid] + dist[mid][to];
                    route[from][to] = route[from][mid];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N - 1; j++)
        {
            if (i == j)
                cout << '-' << ' ';
            else
                cout << route[i][j] << ' ';
        }
        if (i == N)
            cout << '-' << '\n';
        else
            cout << route[i][N] << '\n';
    }
}