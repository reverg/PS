import sys

input = sys.stdin.readline


def sum_decomposition(n, k):
    dp = [[0 for _ in range(k + 1)] for _ in range(n + 1)]
    for i in range(k + 1):
        dp[0][i] = 1

    for i in range(1, n + 1):
        for j in range(1, k + 1):
            # dp[i][j] = (dp[0][j-1] + ... + dp[i-1][j-1]) + dp[i][j-1]
            #          = dp[i-1][j] + dp[i][j-1]
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
            dp[i][j] %= 1000000000

    return dp[n][k]


if __name__ == "__main__":
    N, K = map(int, input().split())

    print(sum_decomposition(N, K))

"""
중복조합으로 풀어도 된다.
k개에서 n개를 뽑는 것과 동일하므로, kHn = (k+n-1)Ck.
"""
