#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int dp[N + 1] = {0};
    for (int i = 0; i < N; i++)
    {
        int time, pay;
        cin >> time >> pay;

        if (i + time <= N)
            dp[i + time] = max(dp[i + time], dp[i] + pay);

        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << dp[N] << '\n';
}