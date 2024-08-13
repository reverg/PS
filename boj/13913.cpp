#include <iostream>
#include <queue>
#include <stack>

#define INF 99999999

using namespace std;

int N, K;
bool visited[100001] = {false};
int prv[100001] = {0};
queue<pair<int, int>> q;

void bfs(int N, int K)
{
    fill(prv, prv + 100001, -1);
    q.push({N, 0});

    while (!q.empty())
    {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();

        if (cur == K)
        {
            cout << time << '\n';
            stack<int> rec;
            int pos = cur;

            while (pos != N)
            {
                rec.push(pos);
                pos = prv[pos];
            }
            rec.push(N);
            while (!rec.empty())
            {
                cout << rec.top() << ' ';
                rec.pop();
            }

            return;
        }

        if (cur - 1 >= 0 && !visited[cur - 1])
        {
            q.push({cur - 1, time + 1});
            visited[cur - 1] = true;
            prv[cur - 1] = cur;
        }

        if (cur + 1 <= 100000 && !visited[cur + 1])
        {
            q.push({cur + 1, time + 1});
            visited[cur + 1] = true;
            prv[cur + 1] = cur;
        }

        if (cur * 2 <= 100000 && !visited[cur * 2])
        {
            q.push({cur * 2, time + 1});
            visited[cur * 2] = true;
            prv[cur * 2] = cur;
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    bfs(N, K);
}

/*
#12851에다 최단경로 역추적.
직전에 방문한 노드를 기록해놨다 거꾸로 돌아가며 출력해주면 된다.
*/