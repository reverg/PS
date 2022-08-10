#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int island_num = 0;
int map[11][11];
bool visited_coord[11][11];
bool visited_island[7];
int parent[7];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, pair<int, int>>> edges;
vector<int> graph[7];

void input()
{
    cin >> N >> M;
    for (int j = 1; j <= N; j++)
        for (int i = 1; i <= M; i++)
            cin >> map[j][i];
}

bool inMap(int y, int x)
{
    return (x >= 1 && x <= M && y >= 1 && y <= N);
}

void dfsIsland(int y, int x)
{
    if (visited_coord[y][x])
        return;

    visited_coord[y][x] = true;
    map[y][x] = island_num;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx))
        {
            if (map[ny][nx] != 0 && !visited_coord[ny][nx])
                dfsIsland(ny, nx);
        }
    }
}

void numberIsland()
{
    // use DFS
    for (int j = 1; j <= N; j++)
    {
        for (int i = 1; i <= M; i++)
        {
            if (map[j][i] != 0)
            {
                if (!visited_coord[j][i])
                    island_num++;
                dfsIsland(j, i);
            }
        }
    }
}

void getEdges()
{
    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= M; x++)
        {

            if (map[y][x] != 0)
            {
                int curIsland = map[y][x];
                for (int i = 0; i < 4; i++)
                {
                    int nx = x;
                    int ny = y;
                    int dist = 0;
                    while (true)
                    {
                        nx += dx[i];
                        ny += dy[i];
                        if (!inMap(ny, nx) || map[ny][nx] == curIsland)
                            break;
                        if (map[ny][nx] != 0)
                        {
                            if (dist >= 2)
                                edges.emplace_back(make_pair(dist, make_pair(curIsland, map[ny][nx])));
                            break;
                        }
                        dist++;
                    }
                }
            }
        }
    }
}

int getParent(int node)
{
    if (parent[node] == node)
        return node;
    else
        return parent[node] = getParent(parent[node]);
}

int kruskal()
{
    int sum = 0;

    for (int i = 1; i <= island_num; i++)
        parent[i] = i;

    for (int i = 0; i < edges.size(); i++)
    {
        int dist = edges[i].first;
        int island1 = edges[i].second.first;
        int island2 = edges[i].second.second;

        island1 = getParent(island1);
        island2 = getParent(island2);

        if (island1 != island2)
        {
            parent[island2] = island1;
            graph[island2].emplace_back(island1);
            graph[island1].emplace_back(island2);
            sum += dist;
        }
    }
    return sum;
}

bool check()
{
    queue<int> q;
    q.push(1);
    int cnt = 1;

    // use BFS
    while (!q.empty())
    {
        int cur_island = q.front();
        q.pop();
        visited_island[cur_island] = true;

        for (int i = 0; i < graph[cur_island].size(); i++)
        {
            int next_island = graph[cur_island][i];
            {
                if (!visited_island[next_island])
                {
                    q.push(next_island);
                    cnt++;
                }
            }
        }
    }

    return (cnt == island_num);
}

void print(bool connected, int ans)
{
    if (connected)
        cout << ans;
    else
        cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    input();
    numberIsland();
    getEdges();
    sort(edges.begin(), edges.end());
    int ans = kruskal();
    bool connected = check();
    print(connected, ans);
}