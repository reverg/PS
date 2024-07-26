#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T = 1;
    while (true)
    {
        int N;
        cin >> N;

        if (N == 0)
            break;

        int cost[N + 1][3];
        for (int i = 1; i <= N; i++)
            cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

        int dp[N + 1][3] = {0};
        dp[1][0] = 1000000000;
        dp[1][1] = cost[1][1];
        dp[1][2] = cost[1][1] + cost[1][2];

        for (int i = 2; i <= N; i++)
        {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][0];
            dp[i][1] = min({dp[i][0], dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + cost[i][1];
            dp[i][2] = min({dp[i][1], dp[i - 1][1], dp[i - 1][2]}) + cost[i][2];
        }

        cout << T << ". " << dp[N][1] << '\n';
        T++;
    }
}