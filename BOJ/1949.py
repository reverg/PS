import sys

sys.setrecursionlimit(100000)

input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    tree = [[] for _ in range(N + 1)]
    population = [0] + list(map(int, input().split()))
    for _ in range(N - 1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)

    dp = [[0, 0] for _ in range(N + 1)]
    visited = [False] * (N + 1)
    visited[1] = True
    st = [1]

    while st:
        cur = st[-1]
        adjacent_pushed = True
        for next in tree[cur]:
            if not visited[next]:
                visited[next] = True
                st.append(next)
                adjacent_pushed = False
        if adjacent_pushed:
            cur = st.pop()
            dp[cur][1] += population[cur]
            for next in tree[cur]:
                # if cur and all nexts are 0,
                # population will be smaller than cur = 1 and all nexts = 0
                # therefore we do not need to consider the third condition
                dp[cur][1] += dp[next][0]
                dp[cur][0] += max(dp[next][0], dp[next][1])

    print(max(dp[1][0], dp[1][1]))
