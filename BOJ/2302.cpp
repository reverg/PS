#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int dp[41];
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= 40; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    int ans = 1;
    int prev_seat = 0;
    for (int i = 0; i < M; i++)
    {
        int new_seat;
        cin >> new_seat;
        ans *= dp[new_seat - prev_seat - 1];
        prev_seat = new_seat;
    }
    ans *= dp[N - prev_seat];

    cout << ans << '\n';
}