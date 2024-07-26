#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> path;
int dist[501];

void BellmanFord(int N)
{
    dist[N] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int idx = 0; idx < path.size(); idx++)
        {
            int from, to, cost;
            tie(from, to, cost) = path[idx];
            if (dist[from] + cost < dist[to])
            {
                dist[to] = dist[from] + cost;
            }
        }
    }

    for (int idx = 0; idx < path.size(); idx++)
    {
        int from, to, cost;
        tie(from, to, cost) = path[idx];
        if (dist[from] + cost < dist[to])
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int TC
            cin >>
        TC;

    while (TC--)
    {
        int N;
        int sticker[100000][2];
        int score[100000][2] = {0};
        cin >> N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < 2; j++)
                cin >> sticker[i][j];

        score[1][0] = sticker[1][0];
        score[1][1] = sticker[1][1];
        for (int i = 2; i < N; i++)
        {
            score[i][0] = max(score[i - 1][1], score[i - 2][1]) + sticker[i][0];
            score[i][1] = max(score[i - 1][0], score[i - 2][0]) + sticker[i][1];
        }
    }
}