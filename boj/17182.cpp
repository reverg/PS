#include <iostream>

#define INF 999999999

using namespace std;

int N, K;

int backtrack(int dist[10][10], int cur, bool visited[10], int traveled, int count)
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
            min_travel_dist = min(min_travel_dist, backtrack(dist, i, visited, travel_dist, count + 1));
            travel_dist -= dist[cur][i];
            visited[i] = false;
        }
    }

    return min_travel_dist;
}

void floydWarshall(int dist[10][10])
{
    for (int mid = 0; mid < N; mid++)
    {
        for (int from = 0; from < N; from++)
        {
            for (int to = 0; to < N; to++)
            {
                if (dist[from][mid] != INF && dist[mid][to] != INF)
                {
                    dist[from][to] = min(dist[from][to], dist[from][mid] + dist[mid][to]);
                }
            }
        }
    }
}

int main()
{
    cin >> N >> K;

    int dist[10][10];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> dist[i][j];

    floydWarshall(dist);        

    bool visited[10] = {false};
    visited[K] = true;
    int min_time = backtrack(dist, K, visited, 0, 1);

    cout << min_time << '\n';
}