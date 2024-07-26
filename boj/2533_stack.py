# python3: 288472KB, 5384ms
# pypy3: 316880KB, 2760ms
import sys

input = sys.stdin.readline

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
    st = [1]

    while st:
        cur = st[-1]
        child_pushed = True
        for next in tree[cur]:
            if not visited[next]:
                visited[next] = True
                st.append(next)
                child_pushed = False
        if child_pushed:
            cur = st.pop()
            dp[cur][1] += 1
            for next in tree[cur]:
                dp[cur][1] += min(dp[next][1], dp[next][0])
                dp[cur][0] += dp[next][1]

    print(min(dp[1][0], dp[1][1]))
