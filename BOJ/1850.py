import sys

input = sys.stdin.readline


def gcd(n1, n2):
    if n1 < n2:
        n1, n2 = n2, n1

    while n2 != 0:
        n1, n2 = n2, n1 % n2

    return n1


if __name__ == "__main__":
    A_len, B_len = map(int, input().split())

    gcd_len = gcd(A_len, B_len)

    print("1" * gcd_len)
