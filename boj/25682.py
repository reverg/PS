import sys

input = sys.stdin.readline


def minimal_board(color):
    prefix_sum = [[0] * (M + 1) for _ in range(N + 1)]
    for i in range(N):
        for j in range(M):
            if (i + j) % 2 == 0:
                val = board[i][j] != color
            else:
                val = board[i][j] == color
            prefix_sum[i + 1][j + 1] = val + (
                prefix_sum[i][j + 1] + prefix_sum[i + 1][j] - prefix_sum[i][j]
            )

    count = sys.maxsize
    for i in range(K, N + 1):
        for j in range(K, M + 1):
            count = min(
                count,
                prefix_sum[i][j]
                - prefix_sum[i][j - K]
                - prefix_sum[i - K][j]
                + prefix_sum[i - K][j - K],
            )
    return count


N, M, K = map(int, input().split())
board = [list(input()) for _ in range(N)]
print(min(minimal_board("B"), minimal_board("W")))
