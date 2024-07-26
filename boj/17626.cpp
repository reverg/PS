#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int N;
    std::cin >> N;
    std::vector<int> dp(N + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        int min_dp = 999999999;
        for (int j = 1; j * j <= i; j++)
        {
            int diff = i - j * j;
            min_dp = std::min(min_dp, dp[diff]);
        }
        dp[i] = min_dp + 1;
    }

    std::cout << dp[N] << '\n';
}