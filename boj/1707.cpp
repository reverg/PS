#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int K, V, E;
vector<int> v[20001];
int visited[20001];

void dfs(int start)
{
    if (visited[start] == 0)
        visited[start] = 1;

    for (int i = 0; i < v[start].size(); i++)
    {
        int idx = v[start][i];
        if (visited[idx] == 0)
        {
            visited[idx] = -visited[start];
            dfs(idx);
        }
    }
}

bool isBipartite()
{
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (visited[i] == visited[v[i][j]])
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    while (K--)
    {
        cin >> V >> E;

        int p1, p2;
        while (E--)
        {
            cin >> p1 >> p2;
            v[p1].push_back(p2);
            v[p2].push_back(p1);
        }

        for (int i = 1; i <= V; i++)
        {
            if (visited[i] == 0)
                dfs(i);
        }

        if (isBipartite() == true)
            cout << "YES\n";
        else
            cout << "NO\n";

        memset(v, 0, sizeof(v));
        memset(visited, 0, sizeof(visited));
    }
}

/*
2가지로 컬러링했을 때 모든 노드가 자기와 인접한 노드와
색이 달라야 한다. BFS로 색칠하고 성립하는지 확인하면 된다.
문제만 읽으면 이해가 잘 안돼서 따로 찾아보는걸 추천.
*/