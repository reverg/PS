import sys

input = sys.stdin.readline


def subsequence(n):
    for i in range(1, n):
        for j in range(i):
            if seq[j] > seq[i]:
                dp[i] = max(dp[i], dp[j] + 1)


if __name__ == "__main__":
    N = int(input())
    seq = list(map(int, input().split()))
    dp = [1] * N  # size of biggest decreasing subsequence

    subsequence(N)
    print(max(dp))

"""
#11053 뒤집으면 된다.
"""
