#include <iostream>

using namespace std;

int main()
{
    int T, W;
    cin >> T >> W;

    int drop[1001];
    for (int i = 1; i <= T; i++)
        cin >> drop[i];

    int dp[1001][32][3];
    dp[1][0][1] = (drop[1] == 1);
    dp[1][1][2] = (drop[1] == 2);
    for (int i = 2; i <= T; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + (drop[i] == 1);
            dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + (drop[i] == 2);
        }
    }

    int ans = 0;
    for (int i = 0; i <= W; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            ans = max(dp[T][i][j], ans);
        }
    }

    cout << ans << '\n';
}