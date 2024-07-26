#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, K;

void bfs()
{
    if (N >= K)
    {
        cout << N - K;
        return;
    }

    bool visited[100001];
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;

    q.push(make_pair(N, 0));

    while (!q.empty())
    {
        int pos = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (K == pos)
        {
            cout << depth;
            break;
        }

        if (pos + 1 <= K && visited[pos + 1] == false)
        {
            visited[pos + 1] = true;
            q.push(make_pair(pos + 1, depth + 1));
        }
        if (pos - 1 >= 0 && visited[pos - 1] == false)
        {
            visited[pos - 1] = true;
            q.push(make_pair(pos - 1, depth + 1));
        }
        if (pos * 2 <= K + 1 && visited[pos * 2] == false)
        {
            visited[pos * 2] = true;
            q.push(make_pair(pos * 2, depth + 1));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;
    bfs();
}