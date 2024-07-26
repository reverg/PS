import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    selections = [0] + list(map(int, input().split()))
    visited = [False] * (n + 1)
    has_team = []

    for i in range(1, n + 1):
        if not visited[i]:
            cycle = []
            dfs = []
            dfs.append(i)
            while len(dfs):
                cur = dfs.pop()
                visited[cur] = True
                cycle.append(cur)
                next = selections[cur]

                if visited[next]:
                    if next in cycle:
                        has_team += cycle[cycle.index(next) :]
                    break
                else:
                    dfs.append(next)

    print(n - len(has_team))
