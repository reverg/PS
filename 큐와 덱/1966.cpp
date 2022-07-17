#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    int n, m, imp;
    while (t--)
    {
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++)
        {
            cin >> imp;
            q.push({i, imp});
            pq.push(imp);
        }

        int cnt = 0, idx;

        while (!q.empty())
        {
            idx = q.front().first;
            imp = q.front().second;
            q.pop();

            if (imp == pq.top())
            {
                pq.pop();
                cnt++;
                if (m == idx)
                {
                    cout << cnt << '\n';
                    break;
                }
            }
            else
                q.push({idx, imp});
        }
    }
}