import sys

input = sys.stdin.readline
MAX_DIST = 4 * 100000


def move(src, dst):
    if src == 0:
        if dst == 0:
            return 0
        else:
            return 2
    elif dst == src:
        return 1
    elif abs(dst - src) == 1 or abs(dst - src) == 3:
        return 3
    else:
        return 4


chaebo = [0] + list(map(int, input().split()))[:-1]
dp = [
    [[MAX_DIST for _ in range(5)] for _ in range(5)] for _ in range(len(chaebo))
]  # score on (note num, left foot, right foot) status
dp[0][0][0] = 0

for i in range(1, len(chaebo)):
    dst = chaebo[i]

    # move left
    for r in range(5):
        for last_l in range(5):
            dp[i][dst][r] = min(dp[i - 1][last_l][r] + move(last_l, dst), dp[i][dst][r])

    # move right
    for l in range(5):
        for last_r in range(5):
            dp[i][l][dst] = min(dp[i - 1][l][last_r] + move(last_r, dst), dp[i][l][dst])

ans = MAX_DIST
for l in range(5):
    for r in range(5):
        ans = min(ans, dp[len(chaebo) - 1][l][r])

print(ans)
