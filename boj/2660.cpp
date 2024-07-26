#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> graph[N + 1];
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int min_score = 50;
    vector<int> candidates;
    for (int i = 1; i <= N; i++)
    {
        queue<int> q;
        int dist[N + 1] = {0};
        bool visited[N + 1] = {false};
        visited[i] = true;
        q.push(i);

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

        int score = 0;
        for (int i = 1; i <= N; i++)
            score = max(score, dist[i]);

        if (min_score > score)
        {
            min_score = score;
            candidates.clear();
            candidates.push_back(i);
        }
        else if (min_score == score)
        {
            candidates.push_back(i);
        }
    }

    cout << min_score << ' ' << candidates.size() << '\n';
    for (int i = 0; i < candidates.size(); i++)
        cout << candidates[i] << ' ';
}