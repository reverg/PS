#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, K;
int dist[201][201];
vector<int> C(200);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // get distance
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        fill(dist[i], dist[i] + N + 1, INF);
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (dist[from][to] > cost)
            dist[from][to] = cost;
    }

    // floyd-warshall
    for (int mid = 1; mid <= N; mid++)
        for (int from = 1; from <= N; from++)
            for (int to = 1; to <= N; to++)
                if (dist[from][to] > dist[from][mid] + dist[mid][to])
                    dist[from][to] = dist[from][mid] + dist[mid][to];

    // get cities
    cin >> K;
    for (int i = 0; i < K; i++)
        cin >> C[i];

    vector<int> ans;
    int min_time = INF * 2;
    for (int i = 1; i <= N; i++)
    {
        int max_time_case = 0;
        for (int j = 0; j < K; j++)
            max_time_case = max(max_time_case, dist[i][C[j]] + dist[C[j]][i]);

        if (min_time > max_time_case)
        {
            ans.clear();
            ans.push_back(i);
            min_time = max_time_case;
        }
        else if (min_time == max_time_case)
            ans.push_back(i);
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}