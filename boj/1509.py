import sys

input = sys.stdin.readline

if __name__ == "__main__":
    S = input().strip()
    L = len(S)
    is_part_palin = [[False for end in range(L)] for start in range(L)]

    # base conditions
    for i in range(L):
        is_part_palin[i][i] = True
    for i in range(1, L):
        if S[i - 1] == S[i]:
            is_part_palin[i - 1][i] = True

    # find palindromes
    for l in range(3, L + 1):
        for start in range(L - l + 1):
            end = start + l - 1
            if S[start] == S[end] and is_part_palin[start + 1][end - 1]:
                is_part_palin[start][end] = 1

    # DP: get minimum palindromes
    dp = [L for _ in range(L + 1)]
    dp[-1] = 0
    for end in range(L):
        for start in range(end + 1):
            if is_part_palin[start][end]:
                dp[end] = min(dp[end], dp[start - 1] + 1)
            else:
                dp[end] = min(dp[end], dp[end - 1] + 1)

    print(dp[L - 1])
