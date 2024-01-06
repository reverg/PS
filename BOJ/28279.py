import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
dq = deque()
for _ in range(N):
    num = list(map(int, input().split()))
    if num[0] == 1:
        dq.appendleft(num[1])
    elif num[0] == 2:
        dq.append(num[1])
    elif num[0] == 3:
        print(dq.popleft() if dq else -1)
    elif num[0] == 4:
        print(dq.pop() if dq else -1)
    elif num[0] == 5:
        print(len(dq))
    elif num[0] == 6:
        print(0 if dq else 1)
    elif num[0] == 7:
        print(dq[0] if dq else -1)
    elif num[0] == 8:
        print(dq[-1] if dq else -1)
