#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 2001
#define INF 999999999

using namespace std;

int T, n, m, t, s, g, h, a, b, d, x;
vector<int> candidate;
vector<pair<int, int>> edge[MAX];

int dist_s[MAX];
int dist_g[MAX];
int dist_h[MAX];

void initialize()
{
    for (int i = 0; i < MAX; i++)
    {
        edge[i].clear();
        dist_s[i] = INF;
        dist_g[i] = INF;
        dist_h[i] = INF;
    }
    candidate.clear();
}

void input()
{
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    while (m--)
    {
        cin >> a >> b >> d;
        edge[a].push_back(make_pair(b, d));
        edge[b].push_back(make_pair(a, d));
    }
    for (int i = 0; i < t; i++)
    {
        cin >> x;
        candidate.push_back(x);
    }
}

void print()
{
    int dist_gh = dist_g[h];
    sort(candidate.begin(), candidate.end());
    for (int i = 0; i < candidate.size(); i++)
    {
        int dest = candidate[i];
        if (dist_s[dest] == dist_s[g] + dist_gh + dist_h[dest])
            cout << dest << ' ';
        else if (dist_s[dest] == dist_s[h] + dist_gh + dist_g[dest])
            cout << dest << ' ';
    }
    cout << '\n';
}

void dijkstra(int start, int dist[MAX])
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty())
    {
        int cur_cost = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        for (int i = 0; i < edge[cur_node].size(); i++)
        {
            int next_node = edge[cur_node][i].first;
            int next_dist = edge[cur_node][i].second;
            if (dist[next_node] > cur_cost + next_dist)
            {
                dist[next_node] = cur_cost + next_dist;
                pq.push(make_pair(-dist[next_node], next_node));
            }
        }
    }
}

void solve()
{
    dijkstra(s, dist_s);
    dijkstra(g, dist_g);
    dijkstra(h, dist_h);
    print();
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--)
    {
        initialize();
        input();
        solve();
    }
}