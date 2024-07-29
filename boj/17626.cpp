#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> dp(N + 1);
    dp[0] = 0;
    dp[1] = 1;
    fill(dp.begin() + 2, dp.end(), 999999999);

    for (int i = 2; i <= N; i++)
    {
        int min_dp = 999999999;
        for (int j = 1; j * j <= i; j++)
        {
            int prev = i - j * j;
            min_dp = min(min_dp, dp[prev]);
        }
        dp[i] = min_dp + 1;
    }

    cout << dp[N] << '\n';
}