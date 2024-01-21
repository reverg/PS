import sys

input = sys.stdin.readline

MOD = 1000000003

N = int(input())
K = int(input())

dp = [[0] * (K + 1) for _ in range(N + 1)]
for i in range(N + 1):
    dp[i][0] = 1
    dp[i][1] = i

for i in range(2, N + 1):
    for j in range(2, K + 1):
        if i == N:
            dp[i][j] = dp[i - 3][j - 1] + dp[i - 1][j]
        else:
            dp[i][j] = dp[i - 1][j] + dp[i - 2][j - 1]
        dp[i][j] %= MOD

print(dp[N][K])
