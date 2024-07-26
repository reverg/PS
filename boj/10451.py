import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    perm = [0] + list(map(int, input().split()))
    visited = [False] * (N + 1)
    result = 0

    for i in range(1, N + 1):
        if not visited[i]:
            dfs = []
            dfs.append(i)
            while dfs:
                cur = dfs.pop()
                visited[cur] = True
                next = perm[cur]

                if visited[next]:
                    result += 1
                    break
                else:
                    dfs.append(next)
    print(result)
