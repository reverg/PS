import sys

input = sys.stdin.readline

N = int(input())

niji_dance = {"ChongChong"}
for i in range(N):
    A, B = input().strip().split()
    if A in niji_dance:
        niji_dance.add(B)
    if B in niji_dance:
        niji_dance.add(A)

print(len(niji_dance))
