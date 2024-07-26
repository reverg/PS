import sys

input = sys.stdin.readline

N = int(input())
cost = [(list(map(int, input().split()))) for _ in range(N)]

COMPLETE = (1 << N) - 1  # bitmask, visited all city
dp = [[0 for _ in range(COMPLETE + 1)] for _ in range(N)]


# visit all unvisited cities start from current city
def DFS(cur, visited):
    if dp[cur][visited] != 0:
        return dp[cur][visited]

    if visited == COMPLETE:
        if cost[cur][0]:
            return cost[cur][0]
        else:
            return float("inf")

    min_dist = float("inf")
    for next in range(1, N):
        if not cost[cur][next] or visited & (1 << next):
            continue
        dist = DFS(next, visited | (1 << next)) + cost[cur][next]
        min_dist = min(dist, min_dist)

    dp[cur][visited] = min_dist
    return min_dist

print(DFS(0, 1))  # start at city #0
