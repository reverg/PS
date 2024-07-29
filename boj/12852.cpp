#include <iostream>

#define INF 2147483647

using namespace std;

int N;
int dp[1000001];
int before[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    dp[1] = 0;
    before[1] = 0;
    for (int i = 2; i <= N; i++)
        dp[i] = INF;

    for (int i = 2; i <= N; i++)
    {
        if (i % 3 == 0)
        {
            if (dp[i] > dp[i / 3] + 1)
            {
                dp[i] = dp[i / 3] + 1;
                before[i] = i / 3;
            }
        }
        if (i % 2 == 0)
        {
            if (dp[i] > dp[i / 2] + 1)
            {
                dp[i] = dp[i / 2] + 1;
                before[i] = i / 2;
            }
        }
        if (dp[i] > dp[i - 1] + 1)
        {
            dp[i] = dp[i - 1] + 1;
            before[i] = i - 1;
        }
    }

    cout << dp[N] << '\n';
    int cur = N;
    while (true)
    {
        cout << cur << ' ';
        if (before[cur] < 1)
            break;
        cur = before[cur];
    }
}