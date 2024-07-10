#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string name[1001];
unordered_map<string, int> id;
vector<int> adj[1001];
int indeg[1001] = {0};
vector<int> ancestors;
vector<int> tr[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> name[i];
    sort(name + 1, name + N + 1);
    for (int i = 1; i <= N; i++)
        id[name[i]] = i;

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        adj[id[s2]].push_back(id[s1]);
        indeg[id[s1]]++;
    }

    for (int i = 1; i <= N; i++)
    {
        if (indeg[i] == 0)
            ancestors.push_back(i);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end());
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (indeg[adj[i][j]] == indeg[i] + 1)
                tr[i].push_back(adj[i][j]);
        }
    }

    cout << ancestors.size() << '\n';
    for (int i = 0; i < ancestors.size() - 1; i++)
        cout << name[ancestors[i]] << ' ';
    cout << name[ancestors[ancestors.size() - 1]] << '\n';

    for (int i = 1; i <= N; i++)
    {
        cout << name[i] << ' ' << tr[i].size();
        for (int j = 0; j < tr[i].size(); j++)
            cout << ' ' << name[tr[i][j]];
        cout << '\n';
    }
}
