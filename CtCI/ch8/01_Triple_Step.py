import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())

    dp = [[0] for _ in range(N + 1)]
    if N == 0:
        print(1)
    elif N == 1:
        print(1)
    elif N == 2:
        print(2)
    else:
        dp[0], dp[1], dp[2] = 1, 1, 2
        for i in range(3, N + 1):
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
        print(dp[N])
