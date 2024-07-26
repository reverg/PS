#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int N, M, X;
int start, fin;
vector<pair<int, int>> edge[2][100001];
int dist[2][1001];

void getInput()
{
    cin >> N >> M >> X;
    int from, to, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        edge[0][to].push_back(make_pair(from, cost));
        edge[1][from].push_back(make_pair(to, cost));
    }
}

void initialize()
{
    for (int i = 1; i <= N; i++)
    {
        dist[0][i] = 999999999;
        dist[1][i] = 999999999;
    }
    dist[0][X] = 0;
    dist[1][X] = 0;
}

void dijkstra(int idx)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, X));

    while (!pq.empty())
    {
        int cur_cost = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (cur_cost > dist[idx][cur_node])
        {
            continue;
        }

        for (int i = 0; i < edge[idx][cur_node].size(); i++)
        {
            int next_node = edge[idx][cur_node][i].first;
            int next_dist = edge[idx][cur_node][i].second;
            if (dist[idx][next_node] > cur_cost + next_dist)
            {
                dist[idx][next_node] = cur_cost + next_dist;
                pq.push(make_pair(-dist[idx][next_node], next_node));
            }
        }
    }
}

int partyTime()
{
    dijkstra(0);
    dijkstra(1);

    int max_dist = 0;
    for (int i = 1; i <= N; i++)
    {
        max_dist = max(max_dist, dist[0][i] + dist[1][i]);
    }

    return max_dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getInput();
    initialize();

    cout << partyTime() << endl;
}