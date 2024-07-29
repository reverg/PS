import sys

input = sys.stdin.readline


def fill_tiles(n):
    if n % 2 == 1:
        return 0

    dp = [0] * (n + 1)
    dp[0] = 1
    dp[2] = 3

    for i in range(4, n + 1):
        dp[i] = dp[i - 2] * 3 + sum(dp[j] for j in range(0, i - 3, 2)) * 2

    return dp[n]


if __name__ == "__main__":
    N = int(input())

    print(fill_tiles(N))

"""
2열 채우는 방법은 3가지이므로 dp[i-2] * 3. 4 이상의 모든 짝수 열은
힌트 3~6열 모양을 쭉 늘려서 만들 수 있다. 위아래로 뒤집을 수 있으므로
(dp[i-4] + ... + dp[0]) * 2. 2가지 경우를 합쳐주면 답이다.
"""
