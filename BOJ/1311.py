import sys

input = sys.stdin.readline

N = int(input())
cost = [(list(map(int, input().split()))) for _ in range(N)]

COMPLETE = (1 << N) - 1  # bitmask, finished all works
dp = [-1 for _ in range(COMPLETE + 1)]

def DFS(cur, visited):
    if cur == N:
        return 0
    if dp[visited] != -1:
        return dp[visited]
    
    dp[visited] = float("inf")
    for next in range(N):
        if not visited & (1 << next):
            dp[visited] = min(dp[visited], DFS(cur+1, visited | (1<<next)) + cost[cur][next])
    return dp[visited]

print(DFS(0, 0))
