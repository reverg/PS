#include <iostream>
#include <queue>
#include <stack>

#define INF 99999999

using namespace std;

int N, K;
bool visited[100001] = {false};
int parent[100001] = {0};
queue<pair<int, int>> q;

void bfs(int N, int K)
{
    for (int i = 0; i < 100001; i++)
        parent[i] = INF;
    q.push(make_pair(N, 0));

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
                pos = parent[pos];
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
            q.push(make_pair(cur - 1, time + 1));
            visited[cur - 1] = true;
            parent[cur - 1] = cur;
        }

        if (cur + 1 <= 100000 && !visited[cur + 1])
        {
            q.push(make_pair(cur + 1, time + 1));
            visited[cur + 1] = true;
            parent[cur + 1] = cur;
        }

        if (cur * 2 <= 100000 && !visited[cur * 2])
        {
            q.push(make_pair(cur * 2, time + 1));
            visited[cur * 2] = true;
            parent[cur * 2] = cur;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;
    bfs(N, K);
}