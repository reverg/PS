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

"""
dp[i][j] = i번째 노드를 얼리어답터로 지정X/지정 할 때 최소 얼리어답터 수
먼저 leaf까지 모조리 다 넣고, leaf부터 root까지 거슬러 올라간다.
거슬러 올라갈 때 전에 값이 기록된 것들은 자식 뿐이므로 계속 stack pop하면
root까지 가는데, parent를 지정하지 않으면 자식들은 모두 얼리어답터야 하고,
parent를 지정하면 자식은 상관 없으므로 둘 중 작은 것을 쓰면 된다.
"""