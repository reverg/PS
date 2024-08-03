# memory over on pypy3
# use python3 to pass: 314060KB, 6176ms
import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline


def dfs(cur):
    for next in tree[cur]:
        if visited[next] == False:
            visited[next] = True
            dfs(next)
            dp[cur][1] += min(dp[next][1], dp[next][0])
            dp[cur][0] += dp[next][1]
    dp[cur][1] += 1


if __name__ == "__main__":
    N = int(input())
    tree = [[] for _ in range(N + 1)]
    for _ in range(N - 1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)

    dp = [[0, 0] for _ in range(N + 1)]
    visited = [False] * (N + 1)
    visited[1] = True

    dfs(1)

    print(min(dp[1][0], dp[1][1]))
