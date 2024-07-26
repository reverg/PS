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

void GetInput()
{
    cin >> N >> W;
    events.emplace_back(make_pair(0, 0)); // for index
    int y, x;
    for (int i = 0; i < W; i++)
    {
        cin >> y >> x;
        events.emplace_back(make_pair(y, x));
    }
}

int GetDistance(int from_y, int from_x, int to_y, int to_x)
{
    return abs(from_y - to_y) + abs(from_x - to_x);
}

void PrintResult()
{
    cout << dp[0][0] << '\n';
    int p1 = 0, p2 = 0;
    for (int i = 0; i < W; i++)
    {
        cout << route[p1][p2] << '\n';
        if (route[p1][p2] == 1)
            p1 = i + 1;
        else
            p2 = i + 1;
    }
}

int DP(int p1, int p2)
{
    // p(i) = the last event which police(i) moved
    if (p1 == W || p2 == W)
        return 0;
    if (dp[p1][p2] != -1)
        return dp[p1][p2];

    int next = max(p1, p2) + 1;
    int dist1, dist2;
    if (p1 == 0)
        dist1 = GetDistance(1, 1, events[next].first, events[next].second);
    else
        dist1 = GetDistance(events[p1].first, events[p1].second, events[next].first, events[next].second);

    if (p2 == 0)
        dist2 = GetDistance(N, N, events[next].first, events[next].second);
    else
        dist2 = GetDistance(events[p2].first, events[p2].second, events[next].first, events[next].second);

    int sum1 = dist1 + DP(next, p2);
    int sum2 = dist2 + DP(p1, next);
    route[p1][p2] = (sum1 < sum2) ? 1 : 2;
    return dp[p1][p2] = min(sum1, sum2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    GetInput();
    memset(dp, -1, sizeof(dp));
    memset(route, -1, sizeof(route));

    DP(0, 0);

    PrintResult();
}