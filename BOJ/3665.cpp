#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int last_ranking[501]; // last year ranking
int entry[501];        // the number of teams in front of team n
int rel[501][501];     // relative position

void swapRelative(int a, int b)
{
    rel[a][b] = 0;
    rel[b][a] = 1;
    entry[a]++;
    entry[b]--;
}

void TopologySort(int N)
{
    queue<int> q;
    vector<int> ranking;

    for (int i = 1; i <= N; i++)
        if (entry[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        ranking.push_back(cur);
        entry[cur]--;

        for (int next = 1; next <= N; next++)
        {
            if (rel[cur][next])
                entry[next]--;

            if (entry[next] == 0)
                q.push(next);
        }
    }

    if (ranking.size() == N)
    {
        for (int i = 0; i < ranking.size(); i++)
            cout << ranking[i] << ' ';
    }
    else
        cout << "IMPOSSIBLE";
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int Tc;
    cin >> Tc;

    int N, M, t, a, b;
    while (Tc--)
    {
        memset(entry, 0, sizeof(entry));
        memset(rel, 0, sizeof(rel));
        
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> last_ranking[i];

        for (int i = 1; i <= N; i++)
        {
            for (int j = i + 1; j <= N; j++)
            {
                rel[last_ranking[i]][last_ranking[j]] = 1;
                entry[last_ranking[j]]++;
            }
        }

        cin >> M;
        for (int i = 1; i <= M; i++)
        {
            cin >> a >> b;
            if (rel[a][b])
                swapRelative(a, b);
            else
                swapRelative(b, a);
        }

        TopologySort(N);
    }
}