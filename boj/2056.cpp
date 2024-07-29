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

/*
위상정렬 + dp. 위상정렬처럼 선행 작업이 없는 것을 다 큐에 넣고,
선행 관계를 하나씩 제거하면서 선행 작업이 다 없어진 것들을 새로
큐에 넣는다. 이 때 작업 시간 갱신을 같이 진행하고 정렬이 다 
끝난 후에 가장 오래 걸린 것을 확인하면 된다.
*/