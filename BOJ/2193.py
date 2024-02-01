import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    dp = [0, 1]  # pinary number ends with 0, 1
    for _ in range(2, N + 1):
        dp = [dp[0] + dp[1], dp[0]]

    print(sum(dp))
