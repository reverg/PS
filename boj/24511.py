import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
isStack = list(map(int, input().split()))
elems = list(map(int, input().split()))
queuestack = deque()
ans = []

M = int(input())
for i in range(N):
    if isStack[i] == 0:
        queuestack.append(elems[i])

inserts = map(int, input().split())
for x0 in inserts:
    queuestack.appendleft(x0)
    ans.append(queuestack.pop())
    
print(*ans)
