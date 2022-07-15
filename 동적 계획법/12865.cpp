#include <iostream>

using namespace std;

int dp[101][100001];
int w[101], v[101];

int knapsack(int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][k];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    cout << knapsack(n, k);
}