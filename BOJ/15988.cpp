#include <iostream>

using namespace std;

#define MOD 1000000009

int main()
{
    long long dp[10000001];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 1000000; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}