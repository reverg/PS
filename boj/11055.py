import sys, copy

input = sys.stdin.readline


def subsequence(n):
    for i in range(1, n):
        for j in range(i):
            if seq[j] < seq[i]:
                dp[i] = max(dp[i], dp[j] + seq[i])


if __name__ == "__main__":
    N = int(input())
    seq = list(map(int, input().split()))
    dp = copy.deepcopy(seq)  # biggest sum ends with seq[i]

    subsequence(N)
    print(max(dp))

"""
#11053과 대동소이. dp 배열 구성 방법은 동일하고 값만
수열의 길이 대신 수열의 합으로 바꿔주면 된다.
"""
