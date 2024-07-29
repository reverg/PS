import sys

input = sys.stdin.readline

N = int(input())
dp = [1] * 10

for i in range(2, N + 1):
    for j in range(1, 10):
        dp[j] += dp[j - 1]

print(sum(dp) % 10007)

"""
dp[j-1]에 이전 dp[0]...dp[j-1]의 합이 들어가 있으므로 매번 더해줄 필요가 없다.
중복된 연산이 제거되어 O(N^2)가 아니라 O(N)에 해결 가능.
"""
