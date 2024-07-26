#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> graph[501];
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool invite[501];
    for (int i = 0; i < graph[1].size(); i++)
    {
        int df = graph[1][i];
        invite[df] = true;
        for (int j = 0; j < graph[df].size(); j++)
            invite[graph[df][j]] = true;
    }

    int ans = 0;
    for (int i = 2; i <= N; i++)
        ans += invite[i];

    cout << ans << '\n';
}