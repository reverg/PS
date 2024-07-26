import sys

input = sys.stdin.readline

N = int(input())
for i in range(N):
    line = (" " * (N - i - 1)) + ("*" * (2 * i + 1))
    print(line)
