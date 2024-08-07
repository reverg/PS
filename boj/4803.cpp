#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[501];
bool visited[501];
int n, m;
int in[100001];
int in_idx[100001];
int post[100001];

void reset()
{
    for (int i = 1; i <= 500; i++)
    {
        visited[i] = false;
        graph[i].clear();
    }
}

bool dfs(int cur, int par)
{
    // cycle check
    if (visited[cur])
        return false;

    visited[cur] = true;

    for (int i = 0; i < graph[cur].size(); i++)
    {
        if (graph[cur][i] == par)
            continue;

        if (!dfs(graph[cur][i], cur))
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num = 1;
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        reset();

        int x, y;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, 0))
                    cnt++;
            }
        }

        cout << "Case " << num << ": ";
        if (cnt == 0)
            cout << "No trees.\n";
        else if (cnt == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << cnt << " trees.\n";
        num++;
    }
}