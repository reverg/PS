#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, R;
int items[101];
int dist[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // get input distance
    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++)
        cin >> items[i];

    for (int i = 1; i <= N; i++)
        fill(dist[i], dist[i] + N + 1, INF);
    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;

    for (int i = 0; i < R; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = dist[b][a] = l;
    }

    // floyd-warshall
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // print result
    int max_item_num = 0;
    for (int i = 1; i <= N; i++)
    {
        int local_items = 0;
        for (int j = 1; j <= N; j++)
            if (dist[i][j] <= M)
                local_items += items[j];

        max_item_num = max(max_item_num, local_items);
    }
    cout << max_item_num << '\n';
}