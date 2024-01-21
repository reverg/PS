import sys

sys.setrecursionlimit(100000)
input = sys.stdin.readline


def dfs(cur):
    dp[cur][1] += weight[cur]
    path[cur][1].append(cur)

    for node in tree[cur]:
        if not visited[node]:
            visited[node] = True
            sub_path = dfs(node)
            dp[cur][0] += max(dp[node][0], dp[node][1])
            dp[cur][1] += dp[node][0]
            path[cur][0] += sub_path[0] if dp[node][0] > dp[node][1] else sub_path[1]
            path[cur][1] += sub_path[0]

    return path[cur]


if __name__ == "__main__":
    N = int(input())
    tree = [[] for _ in range(N + 1)]
    weight = [0] + list(map(int, input().split()))
    for _ in range(N - 1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)

    dp = [[0, 0] for _ in range(N + 1)]
    path = [[[] for _ in range(2)] for _ in range(N + 1)]
    visited = [False] * (N + 1)
    visited[1] = True

    p = dfs(1)

    max_weight_sum, max_weight_path = (
        (dp[1][0], p[0]) if dp[1][0] > dp[1][1] else (dp[1][1], p[1])
    )
    max_weight_path.sort()

    print(max_weight_sum)
    for node in max_weight_path:
        print(node, end=" ")
