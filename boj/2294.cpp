#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int coins[10001];
    for (int i = 0; i < N; i++)
        cin >> coins[i];

    int dp[10001];
    fill(dp + 1, dp + 10001, 999999999);

    for (int j = 0; j < N; j++)
        for (int i = coins[j]; i <= K; i++)
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);

    if (dp[K] != 999999999)
        cout << dp[K] << '\n';
    else
        cout << -1 << '\n';
}

/*
동전 1(#2293)에서 경우의 수 대신 사용한 동전 개수를 구하는 문제.
푸는 방법은 거의 동일하다.
*/