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
            candidates.push_back(i);
    }

    cout << min_score << ' ' << candidates.size() << '\n';
    for (int i = 0; i < candidates.size(); i++)
        cout << candidates[i] << ' ';
}

/*
각각의 회원으로부터 bfs를 해서 최대 거리를 찾으면 된다.
최대 거리를 따로 저장해뒀다가 가장 작은 회원들을 모아서 출력.
회원 수가 50명 이하라 bfs 50번 해도 시간이 넉넉하다.
*/