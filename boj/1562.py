import sys

input = sys.stdin.readline

N = int(input())
FULLMASK = (1 << 10) - 1
MOD = 1000000000

# DP array: end number, 0~9 bitmask (update for every number length)
# start with length 1
dp = [[0] * (FULLMASK + 1) for _ in range(10)]
for i in range(1, 10):
    dp[i][1 << i] = 1

# DP to target length
for length in range(2, N + 1):
    tmp = [[0] * (FULLMASK + 1) for _ in range(10)]
    for i in range(10):
        for j in range(FULLMASK + 1):
            if i > 0:
                tmp[i][j | (1 << i)] += dp[i - 1][j]
                tmp[i][j | (1 << i)] %= MOD
            if i < 9:
                tmp[i][j | (1 << i)] += dp[i + 1][j]
                tmp[i][j | (1 << i)] %= MOD
    dp = tmp

print(sum(dp[i][FULLMASK] for i in range(10)) % MOD)

"""
쉬운 계단 수(#10844)에 비트마스킹을 추가한 버전.
점화식은 #10844와 비슷하고, 0부터 9까지 모두 썼는지만 추가로
확인해주면 되는 문제다.
"""
