# https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1451
# https://sdesigner.tistory.com/52

import sys

input = sys.stdin.readline


def sum_cal(x1, y1, x2, y2):
    return (
        part_sum[x2][y2]
        - part_sum[x2][y1 - 1]
        - part_sum[x1 - 1][y2]
        + part_sum[x1 - 1][y1 - 1]
    )


if __name__ == "__main__":
    N, M = map(int, input().split())

    board = [[0] * (M + 1)]
    board += [[0] + list(map(int, list(input().rstrip()))) for _ in range(N)]

    part_sum = [[0 for _ in range(M + 1)] for _ in range(N + 1)]
    for row in range(1, N + 1):
        for col in range(1, M + 1):
            part_sum[row][col] = (
                part_sum[row - 1][col]
                + part_sum[row][col - 1]
                - part_sum[row - 1][col - 1]
                + board[row][col]
            )

    ans = 0
    # 첫 번째 경우: 전체 직사각형을 세로로만 분할한 경우
    for i in range(1, M - 1):
        for j in range(i + 1, M):
            r1 = sum_cal(1, 1, N, i)
            r2 = sum_cal(1, i + 1, N, j)
            r3 = sum_cal(1, j + 1, N, M)
            if ans < r1 * r2 * r3:
                ans = r1 * r2 * r3

    # 두 번째 경우: 전체 직사각형을 가로로만 분할한 경우
    for i in range(1, N - 1):
        for j in range(i + 1, N):
            r1 = sum_cal(1, 1, i, M)
            r2 = sum_cal(i + 1, 1, j, M)
            r3 = sum_cal(j + 1, 1, N, M)
            if ans < r1 * r2 * r3:
                ans = r1 * r2 * r3

    # 세 번째 경우: 전체 세로 분할 후 우측 가로 분할한 경우
    for i in range(1, M):
        for j in range(1, N):
            r1 = sum_cal(1, 1, N, i)
            r2 = sum_cal(1, i + 1, j, M)
            r3 = sum_cal(j + 1, i + 1, N, M)
            if ans < r1 * r2 * r3:
                ans = r1 * r2 * r3

    # 네 번째 경우: 전체 세로 분할 후 좌측 가로 분할한 경우
    for i in range(1, N):
        for j in range(1, M):
            r1 = sum_cal(1, 1, i, j)
            r2 = sum_cal(i + 1, 1, N, j)
            r3 = sum_cal(1, j + 1, N, M)
            if ans < r1 * r2 * r3:
                ans = r1 * r2 * r3

    # 다섯번 째 경우: 전체 가로 분할 후 하단 세로 분할한 경우
    for i in range(1, N):
        for j in range(1, M):
            r1 = sum_cal(1, 1, i, M)
            r2 = sum_cal(i + 1, 1, N, j)
            r3 = sum_cal(i + 1, j + 1, N, M)
            if ans < r1 * r2 * r3:
                ans = r1 * r2 * r3

    # 여섯번 째 경우: 전체 가로 분할 후 상단 세로 분할한 경우
    for i in range(1, N):
        for j in range(1, M):
            r1 = sum_cal(1, 1, i, j)
            r2 = sum_cal(1, j + 1, i, M)
            r3 = sum_cal(i + 1, 1, N, M)
            if ans < r1 * r2 * r3:
                ans = r1 * r2 * r3

    print(ans)
