#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, T;
int height[301][301];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            height[i][j] = (i == j ? 0 : INF);

    for (int i = 0; i < M; i++)
    {
        int u, v, h;
        cin >> u >> v >> h;
        height[u][v] = h;
    }

    for (int mid = 1; mid <= N; mid++)
        for (int from = 1; from <= N; from++)
            for (int to = 1; to <= N; to++)
                height[from][to] = min(height[from][to], max(height[from][mid], height[mid][to]));

    for (int i = 0; i < T; i++)
    {
        int s, e;
        cin >> s >> e;
        if (height[s][e] != INF)
            cout << height[s][e] << '\n';
        else
            cout << -1 << '\n';
    }
}

/*
플로이드 응용 문제.
거리 계산 부분을 약간 바꿔서 출발 정점에서 도착 정점까지
가는 경로 중 가장 높은 허들 높이를 저장하게 하면 된다.
*/