#include <iostream>
#include <vector>

using namespace std;

const int INF = 999999999;
int N, M;
int dist[101][101];
int nxt[101][101];

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
        dist[from][to] = min(dist[from][to], cost);
        nxt[from][to] = to;
    }

    // Floyd-Warshall
    for (int mid = 1; mid <= N; mid++)
        for (int from = 1; from <= N; from++)
            for (int to = 1; to <= N; to++)
                if (dist[from][to] > dist[from][mid] + dist[mid][to])
                {
                    dist[from][to] = dist[from][mid] + dist[mid][to];
                    nxt[from][to] = nxt[from][mid];
                }

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

    for (int from = 1; from <= N; from++)
    {
        for (int to = 1; to <= N; to++)
        {
            if (dist[from][to] == 0 || dist[from][to] == INF)
            {
                cout << "0\n";
                continue;
            }

            vector<int> path;
            int st = from;
            while (st != to)
            {
                path.push_back(st);
                st = nxt[st][to];
            }
            path.push_back(to);

            cout << path.size() << ' ';
            for (auto x : path)
                cout << x << ' ';
            cout << '\n';
        }
    }
}

/*
#11404 플로이드-워셜에 경로추적 추가.
*/