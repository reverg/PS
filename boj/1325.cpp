#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> graph[N + 1];
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int max_cnt = 0;
    vector<int> result;
    for (int i = 1; i <= N; i++)
    {
        bool visited[N + 1] = {false};

        int cnt = 1;
        queue<int> q;
        q.push(i);

        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            visited[c] = true;

            for (int j = 0; j < graph[c].size(); j++)
            {
                int n = graph[c][j];
                if (visited[n])
                    continue;
                q.push(n);
                visited[n] = true;
                cnt++;
            }
        }

        if (cnt >= max_cnt)
        {
            if (cnt > max_cnt)
            {
                max_cnt = cnt;
                result.clear();
            }

            result.push_back(i);
        }
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
}