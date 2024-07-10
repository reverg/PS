#include <iostream>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

int N, M, A, B;
ll C;
vector<pair<int, int>> graph[100001];
ll cost_record[100001];

struct Gollmok
{
    int node;
    ll max_cost;
    ll payed;
    bool operator()(Gollmok a, Gollmok b)
    {
        if (a.max_cost != b.max_cost)
            return a.max_cost > b.max_cost;
        else
            return a.payed > b.payed;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> A >> B >> C;

    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[to].push_back({from, cost});
        graph[from].push_back({to, cost});
    }

    fill(cost_record, cost_record + 100001, 0x7f7f7f7f7f7f);

    priority_queue<Gollmok, vector<Gollmok>, Gollmok> pq;
    pq.push({A, 0, 0});
    cost_record[A] = 0;

    while (!pq.empty())
    {
        Gollmok cur = pq.top();
        pq.pop();

        if (cur.node == B)
            break;

        for (int i = 0; i < graph[cur.node].size(); i++)
        {
            int next = graph[cur.node][i].first;
            ll cost = graph[cur.node][i].second;
            ll next_max_cost = max(cur.max_cost, cost);

            if (cost_record[next] > next_max_cost && cur.payed + cost <= C)
            {
                cost_record[next] = next_max_cost;
                pq.push({next, next_max_cost, cur.payed + cost});
            }
        }
    }

    cout << (cost_record[B] != 0x7f7f7f7f7f7f ? cost_record[B] : -1) << '\n';
}