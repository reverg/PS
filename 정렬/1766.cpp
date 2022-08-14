#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int entry[100001];
vector<int> node[100001];

void TopologySort(int N)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    // no dependency -> put first
    for (int i = 1; i <= N; i++)
        if (entry[i] == 0)
            pq.push(i);

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        cout << cur << ' ';
        for (int i = 0; i < node[cur].size(); i++)
        {
            int next = node[cur][i];
            entry[next]--;

            // if dependency fully solved, put in queue
            if (entry[next] == 0)
                pq.push(next);
        }
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b; // a stands in front of b
        cin >> a >> b;
        entry[b]++;
        node[a].push_back(b);
    }

    TopologySort(N);
}