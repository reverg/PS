#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int dp[N + 1] = {0};
    for (int i = 0; i < N; i++)
    {
        int time, pay;
        cin >> time >> pay;

        if (i + time <= N)
            dp[i + time] = max(dp[i + time], dp[i] + pay); // 상담 하는 경우

        dp[i + 1] = max(dp[i + 1], dp[i]); // 상담 안하는 경우
    }

    cout << dp[N] << '\n';
}