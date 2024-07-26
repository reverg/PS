import sys

input = sys.stdin.readline


def fact(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * fact(n - 1)


N = int(input())
print(fact(N))
