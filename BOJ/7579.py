import sys

input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
memory = [0] + list(map(int, input().rstrip().split()))
cost = [0] + list(map(int, input().rstrip().split()))
cost_sum = sum(cost)
dp = [[0 for _ in range(cost_sum + 1)] for _ in range(N + 1)]

result = cost_sum
for i in range(1, N + 1):
    for j in range(0, cost_sum + 1):
        if j >= cost[i]:
            dp[i][j] = max(memory[i] + dp[i - 1][j - cost[i]], dp[i - 1][j])
        else:
            dp[i][j] = dp[i - 1][j]

        if dp[i][j] >= M:
            result = min(result, j)

print(result)
