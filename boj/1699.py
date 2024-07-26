import sys

input = sys.stdin.readline


def least_squares(n):
    for i in range(1, n + 1):
        for square in squares:
            if square > i:
                break
            dp[i] = min(dp[i], dp[i - square] + 1)


if __name__ == "__main__":
    N = int(input())
    squares = [pow(i, 2) for i in range(int(pow(N, 0.5)) + 2)]
    dp = [i for i in range(N + 1)]  # minimum number of squares to get i

    least_squares(N)
    print(dp[N])
