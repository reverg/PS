import sys

input = sys.stdin.readline
from collections import Counter

T = int(input())
n = int(input())
A = list(map(int, input().split()))
m = int(input())
B = list(map(int, input().split()))

result = 0
c = Counter()

for start in range(n):
    for end in range(start, n):
        c[sum(A[start : end + 1])] += 1

for start in range(m):
    for end in range(start, m):
        t = T - sum(B[start : end + 1])
        result += c[t]

print(result)
