#include <iostream>
#include <vector>

using namespace std;

int N, M;
int parent[100001];
vector<int> children[1000001];
int score[100001];

void dfs(int x)
{
    if (parent[x] != -1)
        score[x] += score[parent[x]];

    for (int nxt : children[x])
        dfs(nxt);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> parent[i];
        if (parent[i] != -1)
            children[parent[i]].push_back(i);
    }

    while (M--)
    {
        int i, w;
        cin >> i >> w;
        score[i] += w;
    }

    dfs(1);

    for (int i = 1; i <= N; i++)
        cout << score[i] << ' ';
}