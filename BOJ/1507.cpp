#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int dist[20][20];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> dist[i][j];

    bool canRemove[20][20] = {false};
    for (int mid = 0; mid < N; mid++)
    {
        for (int from = 0; from < N; from++)
        {
            for (int to = 0; to < N; to++)
            {
                if (dist[from][to] > dist[from][mid] + dist[mid][to])
                {
                    cout << -1 << '\n';
                    return 0;
                }

                if (from != mid && mid != to && (dist[from][mid] + dist[mid][to] == dist[from][to]))
                {
                    canRemove[from][to] = true;
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            count += (canRemove[i][j] ? 0 : dist[i][j]);
    cout << count / 2 << '\n';
}