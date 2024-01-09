import sys
from collections import deque

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    build_time = [0] + list(map(int, input().split()))
    graph = [[] for _ in range(N + 1)]
    inDegree = [0 for _ in range(N + 1)]
    time_dp = [0 for _ in range(N + 1)]

    # Topological Sort, update time with DP
    for _ in range(K):
        a, b = map(int, input().split())
        graph[a].append(b)
        inDegree[b] += 1

    q = deque()
    for i in range(1, N + 1):
        if inDegree[i] == 0:
            q.append(i)
            time_dp[i] = build_time[i]

    while q:
        src = q.popleft()
        for dst in graph[src]:
            inDegree[dst] -= 1
            time_dp[dst] = max(time_dp[src] + build_time[dst], time_dp[dst])
            if inDegree[dst] == 0:
                q.append(dst)

    trg = int(input())
    print(time_dp[trg])
