import sys

input = sys.stdin.readline


def fill_tiles(n):
    if n % 2 == 1:
        return 0

    dp = [0] * (n + 1)
    dp[2] = 3

    for i in range(4, n + 1):
        dp[i] = dp[i - 2] * 3 + sum(dp[j] for j in range(0, i - 3, 2)) * 2 + 2

    return dp[n]


if __name__ == "__main__":
    N = int(input())

    print(fill_tiles(N))
