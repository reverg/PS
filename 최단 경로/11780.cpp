#include <iostream>
#include <vector>

#define INF 999999999

using namespace std;

int N, M;
bool cycle = false;

long long dist[101][101];
int route[101][101];
vector<pair<pair<int, int>, int>> edge;
vector<int> v;

void Initialize()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dist[i][j] = INF;
    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;
}

void GetInput()
{
    int from, to, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        if (dist[from][to] > cost)
            dist[from][to] = cost;
    }
}

void FindPath(int from, int to)
{
    if (route[from][to] == 0)
    {
        v.push_back(from);
        v.push_back(to);
        return;
    }
    FindPath(from, route[from][to]);
    v.pop_back();
    FindPath(route[from][to], to);
}

void PrintResult()
{
    for (int from = 1; from <= N; from++)
    {
        for (int to = 1; to <= N; to++)
        {
            if (from == to || dist[from][to] == INF)
                cout << "0 ";
            else
                cout << dist[from][to] << ' ';
        }
        cout << '\n';
    }

    for (int from = 1; from <= N; from++)
    {
        for (int to = 1; to <= N; to++)
        {
            if (from == to || dist[from][to] == INF)
                cout << "0 ";
            else
            {
                v.clear();
                FindPath(from, to);
                cout << v.size() << ' ';
                for (int k = 0; k < v.size(); k++)
                    cout << v[k] << ' ';
            }
            cout << '\n';
        }
    }
}

void FloydWarshall()
{
    for (int mid = 1; mid <= N; mid++)
    {
        for (int from = 1; from <= N; from++)
        {
            for (int to = 1; to <= N; to++)
            {
                if (dist[from][mid] != INF && dist[mid][to] != INF)
                {
                    if (dist[from][to] > dist[from][mid] + dist[mid][to])
                    {
                        dist[from][to] = dist[from][mid] + dist[mid][to];
                        route[from][to] = mid;
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    Initialize();

    GetInput();

    FloydWarshall();

    PrintResult();
}