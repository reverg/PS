#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;

int N, K;
int dist[10][10];
bool visited[10];

int backtrack(int cur, int traveled, int count)
{
    if (count == N)
        return traveled;

    int min_travel_dist = INF;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            int travel_dist = traveled + dist[cur][i];
            visited[i] = true;
            min_travel_dist = min(min_travel_dist, backtrack(i, travel_dist, count + 1));
            travel_dist -= dist[cur][i];
            visited[i] = false;
        }
    }

    return min_travel_dist;
}

void floydWarshall()
{
    for (int mid = 0; mid < N; mid++)
        for (int from = 0; from < N; from++)
            for (int to = 0; to < N; to++)
                dist[from][to] = min(dist[from][to], dist[from][mid] + dist[mid][to]);
}

int main()
{
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> dist[i][j];

    floydWarshall();

    visited[K] = true;
    int min_time = backtrack(K, 0, 1);

    cout << min_time << '\n';
}

/*
플로이드-워셜로 거리 다 구하고 백트래킹.
next_permutation 쓰면 더 편하다.
*/