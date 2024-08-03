#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

#define INF 2147483647

using namespace std;

int N, W;
vector<pair<int, int>> events;
int dp[1001][1001];
int route[1001][1001];

inline int getDist(int from_y, int from_x, int to_y, int to_x)
{
    return abs(from_y - to_y) + abs(from_x - to_x);
}

int DP(int e1, int e2)
{
    // e(i) = the last event which police(i) moved
    if (e1 == W || e2 == W)
        return 0;
    if (dp[e1][e2] != -1)
        return dp[e1][e2];

    int next = max(e1, e2) + 1;
    int dist1, dist2;
    if (e1 == 0)
        dist1 = getDist(1, 1, events[next].first, events[next].second);
    else
        dist1 = getDist(events[e1].first, events[e1].second, events[next].first, events[next].second);

    if (e2 == 0)
        dist2 = getDist(N, N, events[next].first, events[next].second);
    else
        dist2 = getDist(events[e2].first, events[e2].second, events[next].first, events[next].second);

    int sum1 = dist1 + DP(next, e2);
    int sum2 = dist2 + DP(e1, next);
    route[e1][e2] = (sum1 < sum2) ? 1 : 2;
    dp[e1][e2] = min(sum1, sum2);

    return dp[e1][e2];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> W;
    events.emplace_back(make_pair(0, 0)); // for index

    int y, x;
    for (int i = 0; i < W; i++)
    {
        cin >> y >> x;
        events.emplace_back(make_pair(y, x));
    }

    memset(dp, -1, sizeof(dp));
    memset(route, -1, sizeof(route));

    DP(0, 0);

    cout << dp[0][0] << '\n';
    int e1 = 0, e2 = 0;
    for (int i = 0; i < W; i++)
    {
        cout << route[e1][e2] << '\n';
        if (route[e1][e2] == 1)
            e1 = i + 1;
        else
            e2 = i + 1;
    }
}

/*
#2342랑 비슷한 느낌의 문제. 시간복잡도는 dp 배열 채우는데
걸리는 시간이랑 동일하므로 O(W^2)가 걸린다.
dp[p1y][p1x][p2y][p2x][event_num]로 하면 메모리가 터진다.
dp[p1이 마지막으로 움직인 사건][p2가 마지막으로 움직인 사건]
으로 하면 현재 위치를 메모리를 훨씬 적게 쓰고 알 수 있다.
이동한 경로는 어느 경찰차가 움직였는지를 저장해놨다가 출력.
*/