import sys

input = sys.stdin.readline


def buy_card(n):
    for i in range(1, n + 1):
        for j in range(max(0, i - n), i):
            dp[i] = max(dp[i], dp[j] + cost[i - j])


if __name__ == "__main__":
    N = int(input())
    cost = [0] + list(map(int, input().split()))
    dp = [0] * (N + 1)  # largest money to buy i cards

    buy_card(N)
    print(max(dp))
