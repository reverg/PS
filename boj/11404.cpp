#include <iostream>

using namespace std;

const int INF = 999999999;
int N, M;
int dist[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    // Initialize & Get input
    for (int i = 1; i <= N; i++)
        fill(dist[i], dist[i] + N + 1, INF);
    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;

    int from, to, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        if (dist[from][to] > cost)
            dist[from][to] = cost;
    }

    // Floyd-Warshall
    for (int mid = 1; mid <= N; mid++)
        for (int from = 1; from <= N; from++)
            for (int to = 1; to <= N; to++)
                if (dist[from][mid] != INF && dist[mid][to] != INF)
                    dist[from][to] = min(dist[from][to], dist[from][mid] + dist[mid][to]);

    // Print answer
    for (int from = 1; from <= N; from++)
    {
        for (int to = 1; to <= N; to++)
        {
            if (from == to || dist[from][to] == INF)
                cout << "0 ";
            else
                cout << dist[from][to] << ' ';
        }
        cout << '\n';
    }
}

/*
기본적인 플로이드-워셜 문제.
경로추적을 추가하면 #11780이 된다.
*/