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

"""
끝부분 처리를 잘 해주면 됨. 마지막 색을 선택하면 양 옆 2개도
선택 불가능하므로 dp[i-3][j-1]이 되고, 선택하지 않으면 1개만
안 고르는 것이므로 dp[i-1][j]. N은 환에 대한 값이고 N-1까지는
선에 대한 값이라 같은 배열로 쓰면 문제 될 소지가 있긴 함.
"""
