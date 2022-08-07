#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define MAX 1001
#define INF 999999999

using namespace std;

int N, M;
int start, fin;
vector<pair<int, int>> edge[MAX];
int dist[MAX];
int before[MAX];
stack<int> route;

void Input()
{
    cin >> N >> M;
    int from, to, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        edge[from].push_back(make_pair(to, cost));
    }
    cin >> start >> fin;
}

void Initialize()
{
    for (int i = 1; i <= N; i++)
        dist[i] = INF;
    dist[start] = 0;
}

void Print()
{
    cout << dist[fin] << '\n';
    int cur = fin;
    while (cur)
    {
        route.push(cur);
        cur = before[cur];
    }
    cout << route.size() << '\n';
    while (!route.empty())
    {
        cout << route.top() << ' ';
        route.pop();
    }
}

void Dijkstra(int start, int fin)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cur_cost = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (cur_cost > dist[cur_node])
            continue;

        for (int i = 0; i < edge[cur_node].size(); i++)
        {
            int next_node = edge[cur_node][i].first;
            int next_dist = edge[cur_node][i].second;
            if (dist[next_node] > cur_cost + next_dist)
            {
                dist[next_node] = cur_cost + next_dist;
                before[next_node] = cur_node;
                pq.push(make_pair(-dist[next_node], next_node));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    Input();
    Initialize();
    Dijkstra(start, fin);
    Print();
}