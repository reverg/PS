import sys

input = sys.stdin.readline


def minProduct(a, b):
    if a > b:
        a, b = b, a
    return minProductHelper(a, b)


def minProductHelper(smaller, bigger):
    if smaller == 0:
        return 0
    elif smaller == 1:
        return bigger

    half_small = smaller >> 1
    half_prod = minProductHelper(half_small, bigger)

    if smaller % 2 == 0:
        return half_prod + half_prod
    else:
        return half_prod + half_prod + bigger


if __name__ == "__main__":
    A, B = map(int, input().split())
    ans = minProduct(A, B)
    print(ans, A * B)
