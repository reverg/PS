import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]
in_degree = [0] * (N + 1)
for i in range(M):
    pd_input = list(map(int, input().split()))
    for idx in range(1, pd_input[0]):
        graph[pd_input[idx]].append(pd_input[idx + 1])
        in_degree[pd_input[idx + 1]] += 1

dq = deque()
ans = []
for i in range(1, N + 1):
    if in_degree[i] == 0:
        dq.append(i)

while dq:
    front = dq.popleft()
    ans.append(front)
    for back in graph[front]:
        in_degree[back] -= 1

        if in_degree[back] == 0:
            dq.append(back)

if len(ans) != N:
    print(0)
else:
    print(*ans, sep="\n")
