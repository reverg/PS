#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> needs[101];
int indeg[101] = {0};
int requirements[101] = {0};

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;
        needs[x].push_back({y, k});
        indeg[y]++;
    }

    // topological sort from finished product -> base parts
    vector<int> base_parts;
    queue<int> q;
    q.push(N);
    requirements[N] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (needs[cur].size() == 0)
            base_parts.push_back(cur);

        for (auto p : needs[cur])
        {
            int need_part = p.first;
            int amount = p.second;
            requirements[need_part] += requirements[cur] * amount;

            indeg[need_part]--;
            if (indeg[need_part] == 0)
                q.push(need_part);
        }
    }

    sort(base_parts.begin(), base_parts.end());
    for (auto bp : base_parts)
        cout << bp << ' ' << requirements[bp] << '\n';
}