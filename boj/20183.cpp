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

/*
다익스트라에서 인자를 3개 사용했다.
최대 수치심이 적은 경로를 먼저 탐색하게 했고, 가지고 있는
금액보다 비싼 경로는 pq에 추가하지 않도록 했다. pq가 empty가
되기 전에 경로를 도착하면 그게 최소 수치심으로 도달할 때 지불하는
비용이 되고, 도달하지 못하면 가지고 있는 금액보다 더 많은 돈을
내야 도달할 수 있다는 뜻이므로 -1을 출력한다.
시간복잡도는 일반 다익스트라와 같은 O(ElogE).
다만 struct를 써서 constant는 좋지 않을 것이다.

최대 수치심의 최솟값을 parametric search로 찾아서 다익스트라를
여러 번 돌리는 풀이도 가능하다. 이 경우엔 O(ElogE * log(최대수금액)).
해당 풀이는 아래 링크 참조:
https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x1D/solutions/20183.cpp
*/