#include <iostream>

using namespace std;

int N, M, R;
int items[101];
int dist[101][101];

void input()
{
    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++)
    {
        cin >> items[i];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i != j)
                dist[i][j] = (1 << 15);
        }
    }
    for (int i = 0; i < R; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = dist[b][a] = l;
    }
}

void floydWarshall()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int getMaxItemNum()
{
    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        int local_items = 0;
        for (int j = 1; j <= N; j++)
        {
            if (dist[i][j] <= M){
                local_items += items[j];
            }
        }
        result = max(result, local_items);
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    floydWarshall();
    cout << getMaxItemNum() << endl;
}