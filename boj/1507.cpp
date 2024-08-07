#include <iostream>

using namespace std;

int N;
int dist[20][20];
bool canRemove[20][20] = {false};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> dist[i][j];

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
                    canRemove[from][to] = true;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            count += (canRemove[i][j] ? 0 : dist[i][j]);
    cout << count / 2 << '\n';
}

/*
플로이드를 반대로 돌린다.
어떤 도로가 다른 두 도로의 합으로 표현된다는 것은,
그 도로를 없애도 지장이 없다는 뜻이다.
22행처럼 최단경로가 덜 완성된건 불가능한 경우이다.
양방향 간선에서 거리가 2배로 세지므로 마지막에 2로 나눠줬다.
*/