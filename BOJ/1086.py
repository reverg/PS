import sys, math

input = sys.stdin.readline

N = int(input())
nums = [int(input()) for _ in range(N)]
K = int(input())

COMPLETE = (1 << N) - 1  # bitmask, appended all numbers
dp = [[0] * K for _ in range(COMPLETE + 1)]  # dp[status][mod K]
dp[0][0] = 1

remains = [[[0] for _ in range(K)] for _ in range(N)]  # pre-calculated mods
for j in range(K):
    for i in range(N):
        head = (j * (10 ** len(str(nums[i])))) % K
        tail = nums[i] % K
        remains[i][j] = (head + tail) % K

for b in range(1 << N):
    for i in range(N):
        if b & (1 << i):  # already used this number
            continue
        for j in range(K):
            dp[b | (1 << i)][remains[i][j]] += dp[b][j]

p = dp[COMPLETE][0]
q = sum(dp[COMPLETE])
g = math.gcd(p, q)
print(f"{p//g}/{q//g}")
