#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, Q;
vector<pair<int, int>> bulldog;
int wait[501][501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++)
    {
        int d;
        cin >> d;
        bulldog.push_back({d, i});
        wait[i][i] = d;
    }
    sort(bulldog.begin(), bulldog.end());

    int dist[501][501];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dist[i][j] = (i == j ? 0 : INF);
            wait[i][j] = max(wait[i][i], wait[j][j]);
        }
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        dist[a][b] = d;
        dist[b][a] = d;
    }

    // 개가 괴롭힐 수 있는 시간 기준으로 오름차순 정렬하고 탐색
    // 개는 가장 오래 괴롭힐 수 있는 곳에서 기다리므로 이전에 확인한 지점들에서 기다리지 않음
    // 결과적으로 새로 경유하게 되는 지점, 시작점, 끝점 중 하나에서만 기다리므로 최소 시간 보장 가능
    for (int mIdx = 0; mIdx < N; mIdx++)
    {
        pair<int, int> mid = bulldog[mIdx];
        for (int from = 1; from <= N; from++)
        {
            for (int to = 1; to <= N; to++)
            {
                int mWait = mid.first;
                int mNode = mid.second;

                int newDist = dist[from][mNode] + dist[mNode][to];
                int newWait = max(mWait, wait[from][to]);
                if (dist[from][to] + wait[from][to] > newDist + mWait)
                {
                    dist[from][to] = newDist;
                    wait[from][to] = newWait;
                }
            }
        }
    }

    while (Q--)
    {
        int s, t;
        cin >> s >> t;
        int total_time = dist[s][t] + wait[s][t];
        cout << (total_time < INF ? total_time : -1) << '\n';
    }
}

/*
#23258의 강화판인 플로이드-와셜 문제.
가장 바깥 루프에서 선택하는 정점이 경로에 사용 가능하도록 추가되는 점임을
명심하자. 개가 오랫동안 괴롭힐 수 있는 순서로 정렬하고 경로를 갱신하면
자동적으로 개가 가장 오랫동안 괴롭힐 수 있는 지점에서 대기하게 된다.
정렬하지 않고 갱신하면 괴롭힐 수 있는 시간이 짧은 지점에서 기다릴 때
총 시간이 가장 긴 tc에서 오답이 나온다.
61행에서 newWait를 계산한 것은 경유하는 지점 뿐만 아니라 시작점과 끝점에서도
개가 대기할 수 있기 때문이다. 알고리즘이 경유점 기준으로 거리를 갱신하므로
시작점과 끝점은 따로 고려가 필요하다.
*/