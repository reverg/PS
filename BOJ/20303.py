import sys

input = sys.stdin.readline


def find(v):
    if group[v] != v:
        group[v] = find(group[v])
    return group[v]


def union(v1, v2):
    r1, r2 = find(v1), find(v2)
    if r1 > r2:
        group[r1] = r2
    else:
        group[r2] = r1


if __name__ == "__main__":
    N, M, K = map(int, input().split())
    candies = [0] + list(map(int, input().split()))
    group = [i for i in range(N + 1)]

    # get friends group
    for _ in range(M):
        c1, c2 = map(int, input().split())
        union(c1, c2)

    # count candies for each group
    cnt_friends = [1] * (N + 1)
    for i in range(1, N + 1):
        if i != group[i]:
            root = find(i)
            candies[root] += candies[i]
            cnt_friends[root] += cnt_friends[i]

    # DP
    dp = [0 for _ in range(K)]
    for i in range(1, N + 1):
        if i != group[i]:
            continue
        for j in range(K - 1, cnt_friends[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - cnt_friends[i]] + candies[i])

    print(max(dp))
