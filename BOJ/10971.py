import sys

input = sys.stdin.readline


def dfs(curr, sum):
    global visited, ans

    # visited all, go back to start
    if visited == (1 << N) - 1:
        if cost[curr][0] != 0:
            sum += cost[curr][0]
            if ans > sum:
                ans = sum
        return

    for next in range(N):
        if (not visited & (1 << next)) and cost[curr][next] != 0:
            visited += 1 << next
            dfs(next, sum + cost[curr][next])
            visited -= 1 << next


if __name__ == "__main__":
    N = int(input())
    cost = [list(map(int, input().split())) for _ in range(N)]
    visited = 0  # use bitmask

    ans = 10000000
    visited += 1 << 0
    dfs(0, 0)

    print(ans)
