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

"""
채보에 맞게 왼발과 오른발을 각각 옮겨보면서 비용이 적은 것을 저장하면 된다.
같은 지점에 두 발을 두면 안된다는 조건을 따로 처리하진 않았지만, 어차피
밟고 있는 발로 다시 밟는게 비용이 더 적어서 결과에 반영되진 않는다.
"""
