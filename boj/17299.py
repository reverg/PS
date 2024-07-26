import sys

input = sys.stdin.readline
from collections import Counter

N = int(input())
data = list(map(int, input().split()))
count = Counter(data)
stack = []
result = [-1] * N
stack.append(0)

for i in range(N):
    while stack and count[data[stack[-1]]] < count[data[i]]:
        result[stack.pop()] = data[i]
    stack.append(i)

print(*result)
