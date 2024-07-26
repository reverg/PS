#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int entry[10001] = {0};
    int time[10001] = {0};
    vector<int> node[10001];
    for (int i = 1; i <= N; i++)
    {
        int f;
        cin >> time[i] >> f;
        for (int j = 0; j < f; j++)
        {
            int a;
            cin >> a;
            node[a].push_back(i);
            entry[i]++;
        }
    }

    queue<int> q;
    int result[10001] = {0};
    for (int i = 1; i <= N; i++)
    {
        if (entry[i] == 0)
            q.push(i);

        result[i] = time[i];
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < node[cur].size(); i++)
        {
            int next = node[cur][i];
            entry[next]--;
            result[next] = max(result[next], result[cur] + time[next]);

            if (entry[next] == 0)
                q.push(next);
        }
    }

    int ans = -1;
    for (int i = 1; i <= N; i++)
        ans = max(ans, result[i]);
    cout << ans << '\n';
}