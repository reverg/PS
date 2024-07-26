#include <iostream>

using namespace std;

int main()
{
    int T, N;
    cin >> T;
    while (T--)
    {
        int N, M, coins[20];
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> coins[i];
        cin >> M;

        int dp[M + 1] = {0};
        dp[0] = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = coins[i]; j <= M; j++)
            {
                    dp[j] += dp[j - coins[i]];
            }
        }

        cout << dp[M] << '\n';
    }
}