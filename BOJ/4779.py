import sys

input = sys.stdin.readline


def cantor_set(n):
    if n == 0:
        return "-"
    else:
        small_unit = cantor_set(n - 1)
        middle_space = " " * (3 ** (n - 1))
        return small_unit + middle_space + small_unit


while True:
    try:
        N = int(input())
        print(cantor_set(N))
    except:
        break
