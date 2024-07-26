#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void bfs(int A, int B)
{
    bool visited[10000] = {false};
    pair<int, char> parent[10000];
    queue<int> q;

    q.push(A);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == B)
        {
            stack<char> rec;
            pair<int, char> pos = parent[B];

            while (pos.first != A)
            {
                rec.push(pos.second);
                pos = parent[pos.first];
            }
            rec.push(pos.second);

            while (!rec.empty())
            {
                cout << rec.top();
                rec.pop();
            }
            cout << '\n';
            return;
        }

        // D
        int D = (cur * 2) % 10000;
        if (!visited[D])
        {
            q.push(D);
            visited[D] = true;
            parent[D] = make_pair(cur, 'D');
        }

        // S
        int S = ((cur >= 1) ? cur - 1 : 9999);
        if (!visited[S])
        {
            q.push(S);
            visited[S] = true;
            parent[S] = make_pair(cur, 'S');
        }

        // L
        int L = (cur % 1000) * 10 + (cur / 1000);
        if (!visited[L])
        {
            q.push(L);
            visited[L] = true;
            parent[L] = make_pair(cur, 'L');
        }

        // R
        int R = (cur % 10) * 1000 + (cur / 10);
        if (!visited[R])
        {
            q.push(R);
            visited[R] = true;
            parent[R] = make_pair(cur, 'R');
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int A, B;
        cin >> A >> B;
        bfs(A, B);
    }
}