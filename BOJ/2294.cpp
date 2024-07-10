#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    int coins[10001];
    for (int i = 0; i < N; i++)
        cin >> coins[i];

    int dp[10001];
    for (int i = 1; i <= K; i++)
        dp[i] = 999999999;

    for (int j = 0; j < N; j++)
    {
        for (int i = coins[j]; i <= K; i++)
        {
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }

    if (dp[K] != 999999999)
        cout << dp[K] << '\n';
    else
        cout << -1 << '\n';
}
