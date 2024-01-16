import sys

input = sys.stdin.readline


def count_one(n):
    if n < 2:
        return n

    order = 0
    while (1 << order) <= n:
        order += 1
    order -= 1

    m = 1 << order
    r = n - m
    return (order * (m // 2)) + (r + 1) + count_one(r)


if __name__ == "__main__":
    A, B = map(int, input().split())
    print(count_one(B) - count_one(A - 1))
