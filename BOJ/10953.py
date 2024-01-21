import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    A, B = map(int, input().split(sep=","))
    print(A + B)
