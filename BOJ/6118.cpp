#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> graph[N + 1];
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int dist[N + 1] = {0};
    bool visited[N + 1] = {false};
    queue<int> q;
    visited[1] = true;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];

            if (!visited[next])
            {
                dist[next] = dist[cur] + 1;
                visited[next] = true;
                q.push(next);
            }
        }
    }

    int max_dist = 0;
    int hide_hutgan = 0;
    int max_count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] > max_dist)
        {
            hide_hutgan = i;
            max_dist = dist[i];
            max_count = 1;
        }
        else if (dist[i] == max_dist)
        {
            max_count++;
        }
    }

    cout << hide_hutgan << ' ' << max_dist << ' ' << max_count << '\n';
}