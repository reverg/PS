#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int dp[1000001] = {0};
    int x, ans = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> x;
        dp[x] = dp[x - 1] + 1;
        ans = max(ans, dp[x]);
    }

    cout << N - ans << '\n';
}