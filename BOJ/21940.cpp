#include <iostream>
#include <vector>
#include <algorithm>

#define INF 999999999

using namespace std;

void FloydWarshall(long long dist[201][201], int N)
{
    for (int mid = 1; mid <= N; mid++)
    {
        for (int from = 1; from <= N; from++)
        {
            for (int to = 1; to <= N; to++)
            {
                if (dist[from][mid] != INF && dist[mid][to] != INF)
                {
                    if (dist[from][to] > dist[from][mid] + dist[mid][to])
                    {
                        dist[from][to] = dist[from][mid] + dist[mid][to];
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    long long dist[201][201];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dist[i][j] = INF;
    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;

    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (dist[from][to] > cost)
            dist[from][to] = cost;
    }

    FloydWarshall(dist, N);

    int K;
    cin >> K;
    vector<int> C(K);
    for (int i = 0; i < K; i++)
        cin >> C[i];

    vector<int> ans;
    long long min_time = INF;
    for (int i = 1; i <= N; i++)
    {
        long long max_time_case = 0;
        for (int j = 0; j < K; j++)
        {
            if (dist[i][C[j]] != INF && dist[C[j]][i] != INF)
                max_time_case = max(max_time_case, dist[i][C[j]] + dist[C[j]][i]);
        }

        if (min_time > max_time_case)
        {
            ans.clear();
            ans.push_back(i);
            min_time = max_time_case;
        }
        else if (min_time == max_time_case)
        {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}